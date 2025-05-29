#include <stdio.h>
#include <string.h>

int main() {

    char frase[]= "Me gusta programar en C";
    char *ptr = strstr(frase,"programar");

    if (ptr !=NULL){
        printf("la subcadena esta en: %s\n",ptr);
    }else{
        printf("subcadena no encontrada\n");
    }
    return 0;
}