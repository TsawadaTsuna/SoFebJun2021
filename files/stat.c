#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(int argnum, char **argv){
    char *path = argv[1];
    struct stat sb;
    if(stat(path,&sb)==-1){
        printf("Error en el archivo\n");
        return -1;
    }

    if(S_ISDIR(sb.st_mode)){
        printf("Directorio encontrado \n");
    }

    if(S_ISREG(sb.st_mode)){
        printf("Archivo normal \n");
    }
    return 0;
}