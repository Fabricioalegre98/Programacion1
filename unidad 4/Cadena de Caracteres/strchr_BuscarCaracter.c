#include <stdio.h>
#include <string.h>

int main() {

    char palabra[] = "computadora";
    char *ptr = strchr(palabra, 'u');

    if (ptr != NULL){
        printf("encontrado: %c en la posicion: %d\n", *ptr, ptr - palabra);
    }else {
        printf("el caracter 'u' no se encuentra en la cadena\n");
    }

    return 0;
}