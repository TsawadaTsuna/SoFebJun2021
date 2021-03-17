#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varGlobal;

void signalHandler(int sig){
  printf("Recibi segnal %d\n", sig);
	if(sig==15){
		varGlobal=0;
	}
}

int main(){
	varGlobal=1;
  signal(2, signalHandler);
  signal(15, signalHandler);
  while(varGlobal){
    printf("Trabajando\n");
    sleep(1);
  }
  printf("Ya voy a terminar \n");
  return 0;
}