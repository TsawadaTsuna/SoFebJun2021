#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv){
    char *dirname = argv[1];
    DIR *dir = opendir(dirname);
    struct dirent *dirContent;
    while(dirContent = readdir(dir)){
        printf("file %s esta en %lu \n",dirContent->d_name,dirContent->d_ino);
    }
    closedir(dir);
    return 0;
}