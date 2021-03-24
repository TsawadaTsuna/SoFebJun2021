#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int procesoTerminado=0;

void signalHandler(int sig){
	procesoTerminado=wait(NULL);
    printf("Acabo el hijo %d\n", procesoTerminado);
}

int main(){
	signal(17, signalHandler);
	int pid = fork();
	int pidHijoTermino;
	if (pid==0){
		//proceso hijo
		printf("Soy el process hijo\n");
	}else{
		printf(" Soy padre y mi hijo es %d\n",pid);
		
		//pidHijoTermino=wait(NULL);
		int a = 1;
		while(a){
			printf("Trabajamdo \n");
			if (procesoTerminado>0){
				a=0;
			}
			sleep(1);
		}
		printf("Mi hijo acabo %d \n",procesoTerminado);
	}
	printf("Terminao\n");
	return 0;
}