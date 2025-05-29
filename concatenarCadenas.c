#include <stdio.h>
#include <string.h>

int main(){
    char saludo[20] = "hola ";
    char nombre[] = "fabricio";

    strcat(saludo, nombre);
    printf("El saludo es: %s\n", saludo);
    return 0;

}