#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[80], ch;
    int dato;
    scanf("%s %d", str, &dato);
    while((fgetc(stdin))!= '\n');
    fprintf(stdout,"%s", str); // fprintf = printf
    printf("%d \n", dato);
    fflush(stdout);
    return 0;
}