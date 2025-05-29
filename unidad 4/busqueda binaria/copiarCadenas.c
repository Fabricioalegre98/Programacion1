#include <stdio.h>
#include <string.h>

int main(){
    char origen[]= "Hola, mundo!";
    char destino[50];

    strcpy(destino, origen); // Copia la cadena de origen a destino

    printf("cadena de caracteres original: %s\n", origen);
    return 0;
}