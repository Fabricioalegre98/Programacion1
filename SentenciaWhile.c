#include <stdio.h>

int main () {

    int contador = 10;

    while (contador <= 500) {
        printf("contador %d\n", contador);
        contador*=2;
    }

    return 0;    
}