#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argnum, char **argv){
    char *original = argv[1];
    char *destino = argv[2];
    char buffer;
    int size=0;
    FILE *foriginal, *fdestino;
    foriginal = fopen(original,"rb");
    fdestino = fopen(destino,"wb");
    while(fread(&buffer,sizeof(char),1,foriginal)){
        if(buffer == '\n'){
            char *linea;
            size += 1;
            fseek(foriginal, -size, SEEK_CUR);
            linea = (char *) calloc(size, sizeof(char)); // linea[size];
            fread(linea,sizeof(char),size,foriginal);
            if(strstr(linea,"hola") == NULL){
                fwrite(linea,sizeof(char),size,fdestino);
            }
            size = 0;
            free(linea);
        } else {
            size += 1;
        }
        //fwrite(&buffer,sizeof(char),1,fdestino);
    }
    if(size>0){
        char *linea;
        fseek(foriginal, -size, SEEK_CUR);
        linea = (char *) calloc(size, sizeof(char)); // linea[size];
        fread(linea,sizeof(char),size,foriginal);
        if(strstr(linea,"hola") == NULL){
            fwrite(linea,sizeof(char),size,fdestino);
        }
        size = 0;
        free(linea);
    }
    fclose(foriginal);
    fclose(fdestino);

    return 0;
}
