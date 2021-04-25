#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    char fun[20];
    float inicio,final,puntos;
    int pah[2];
    int hap[2];
    pipe(pah);
    pipe(hap);
    int pid = fork();
	if(pid==0){
		// Hijo
        // connect pc2p to stdout
        close(pah[1]);
        close(hap[0]);
        //(pah[0], hap[1]);
        FILE *in = fdopen(pah[0], "r");
        FILE *out = fdopen(hap[1], "w");
        char params[50];
        fscanf(in,"%s",params);
        printf("%s\n",params);
		//execl("/usr/bin/bc","bc","-l",params,NULL);
	}
	if(pid>0){
		// Padre
		close(pah[0]);
        close(hap[1]);
        FILE *out = fdopen(pah[1], "w");
        FILE *in = fdopen(hap[0], "r");
        int sum=0;
        
        scanf("%s",fun);
        printf("%s",fun);
        scanf("%f %f %f",&inicio,&final,&puntos);
        
        /*
        while(fscanf(in, "%s", fun) !=EOF){
				printf("%s\n", fun);
			}
			fclose(in);
            */
        //fprintf(out,"x=%f\n %s\n",inicio,fun);
        //fprintf(out,"x=%f %s",inicio,fun);
        //fprintf(out,"%f %f",inicio,final);

	}
    
    
}