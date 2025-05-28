#include <stdio.h>

int main(){
    int numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int encontrado = 0;
    int buscado = 11; //buscar el numero 7
    for (int i=0; i<10; i++){
        if (numeros[i]==buscado){
            printf("se encuentra el numero %d en la posicion %d\n", buscado, i);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado){
        printf("no se encuentra el numero %d\n", buscado);
    }
    return 0;
}