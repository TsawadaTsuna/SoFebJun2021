#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int pah[2];//padre a hijo
    int hap[2];//hijo a padre
    pipe(pah);
    pipe(hap);
    int pid = fork();
	if(pid==0){
		// Hijo
        close(pah[1]);
        dup2(pah[0], STDIN_FILENO);
        close(pah[0]);
        close(hap[0]);
        dup2(hap[1], STDOUT_FILENO);
        close(hap[1]);
        execlp("/usr/bin/bc", "bc", "-l", NULL);
	}else if(pid>0){
		// Padre
		close(pah[0]);
        close(hap[1]);
        FILE *out = fdopen(pah[1], "w");//escritura de padre a hijo
        FILE *in = fdopen(hap[0], "r");//lectura de hijo a padre
        char fun[100];
		float inicio, final, actual, sum, promedio, res;
		int puntos;
        while(1){
            while (scanf("%s", fun) != EOF) {
                scanf("%f %f %d",&inicio,&final,&puntos);
                for(int i=0;i< puntos;i++){
                    actual = inicio+((final-inicio)/puntos)*(i+1);
                    fprintf(out, "x=%f\n", actual);
					fprintf(out, "%s\n", fun);
					fflush(out);
                    fscanf(in, "%f", &res);
					fflush(in);
					sum += res;
                }
                promedio = sum/(puntos+1);
				printf("Promedio: %f\n", promedio);
				sum = 0;
				puntos=0;
            }
        }
        }else{

        }
        return 0;
}