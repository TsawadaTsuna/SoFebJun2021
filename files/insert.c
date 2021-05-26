#include <stdio.h>
#include "./student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    FILE *fdestino;
    fdestino = fopen(filename,"wb");
    int cuantos;
    printf("CUantos alumnos a insertar: ");
    scanf("%d",&cuantos);
    for(int i=0;i<cuantos; i++){
        STUDENT newstud;
        printf("nombre: ");
        scanf("%s",newstud.name);
        printf("apellido: ");
        scanf("%s",newstud.lastname);
        printf("id: ");
        scanf("%d",&newstud.id);
        printf("semestre: ");
        scanf("%d",&newstud.semestre);
        //printf("%s %s %d %d\n",newstud.name,newstud.lastname,newstud.id,newstud.semestre);
        fwrite(&newstud,sizeof(newstud),1,fdestino);
    }
    fclose(fdestino);
}