#include <stdio.h>
#include <stdlib.h>
#include "./student.h"

int main(int argc, char **argv){
    char *filename = argv[1];
    int cuantos = atoi(argv[2]);
    FILE *foriginal;
    foriginal = fopen(filename,"rb");
    for(int i=0;i<cuantos; i++){
        STUDENT newstud;
        fread(&newstud,sizeof(newstud),1,foriginal);
        printf("nombre: %s\n",newstud.name);
        printf("apellido: %s\n",newstud.lastname);
        printf("id: %d\n",newstud.id);
        printf("semestre: %d\n",newstud.semestre);
        //printf("%s %s %d %d\n",newstud.name,newstud.lastname,newstud.id,newstud.semestre);
        //fwrite(&newstud,sizeof(newstud),1,fdestino);
    }
    fclose(foriginal);
}