#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    char *filtro = argv[2];
    char *buscado = argv[3];
    char *nuevo = argv[4];
    FILE *foriginal;
    foriginal = fopen(filename,"rb+");
    STUDENT newstud;
    while(fread(&newstud,sizeof(newstud),1,foriginal)){
        if(strcmp(filtro,"name")==0&&strcmp(newstud.name,buscado)==0){
            strcpy(newstud.name, nuevo);
            fseek(foriginal,-1*sizeof(newstud),SEEK_CUR);
            fwrite(&newstud,sizeof(newstud),1,foriginal);
        }
        if(strcmp(filtro,"lastname")==0&&strcmp(newstud.lastname,buscado)==0){
            strcpy(newstud.lastname, nuevo);
            fseek(foriginal,-1*sizeof(newstud),SEEK_CUR);
            fwrite(&newstud,sizeof(newstud),1,foriginal);
        }
        if(strcmp(filtro,"id")==0&& newstud.id==atoi(buscado)){
            newstud.id = atoi(nuevo);
            fseek(foriginal,-1*sizeof(newstud),SEEK_CUR);
            fwrite(&newstud,sizeof(newstud),1,foriginal);
        }
        if(strcmp(filtro,"semestre")==0&& newstud.semestre==atoi(buscado)){
            newstud.semestre = atoi(nuevo);
            fseek(foriginal,-1*sizeof(newstud),SEEK_CUR);
            fwrite(&newstud,sizeof(newstud),1,foriginal);
        }
        
    }
    fclose(foriginal);
}