#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUMTHREADS 50
int total;
pthread_mutex_t lock;
void *suma(void *datos){
    printf("Hello world desde hilo %d\n",*(int *)datos);
    pthread_mutex_lock(&lock);
    total+=100;
    pthread_mutex_unlock(&lock);

    pthread_exit(NULL);
}

int main(){
    pthread_t myThreads[NUMTHREADS];
    int tIds[NUMTHREADS];
    pthread_mutex_init(&lock,NULL);
    pthread_mutex_unlock(&lock);
    for(int i=0;i<NUMTHREADS; i++){
        tIds[i]=i;
        pthread_create(&myThreads[i],NULL,suma,&tIds[i]);
    }
    for(int i=0;i<NUMTHREADS; i++){
        pthread_join(myThreads[i],NULL);
    }
    printf("suma: %d\n",total);
    pthread_exit(NULL);
}