#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    char *filtro = argv[2];
    char *buscado = argv[3];
    FILE *foriginal;
    foriginal = fopen(filename,"rb");
    STUDENT newstud;
    while(fread(&newstud,sizeof(newstud),1,foriginal)){
        if(strcmp(filtro,"name")==0&&strcmp(newstud.name,buscado)==0){
            printf("nombre: %s\n",newstud.name);
            printf("apellido: %s\n",newstud.lastname);
            printf("id: %d\n",newstud.id);
            printf("semestre: %d\n",newstud.semestre);
        }else if(strcmp(filtro,"lastname")==0&&strcmp(newstud.lastname,buscado)==0){
            printf("nombre: %s\n",newstud.name);
            printf("apellido: %s\n",newstud.lastname);
            printf("id: %d\n",newstud.id);
            printf("semestre: %d\n",newstud.semestre);
        }else if(strcmp(filtro,"id")==0&& newstud.id==atoi(buscado)){
            printf("nombre: %s\n",newstud.name);
            printf("apellido: %s\n",newstud.lastname);
            printf("id: %d\n",newstud.id);
            printf("semestre: %d\n",newstud.semestre);
        }else if(strcmp(filtro,"semestre")==0&& newstud.semestre==atoi(buscado)){
            printf("nombre: %s\n",newstud.name);
            printf("apellido: %s\n",newstud.lastname);
            printf("id: %d\n",newstud.id);
            printf("semestre: %d\n",newstud.semestre);
        }
    }
    fclose(foriginal);
}