#include <stdio.h>

int main() {
    int numeros[] = {10,20,30,40,50};
    int size = sizeof(numeros) / sizeof(numeros[0]);
    //imprime el arreglo original
    printf("arreglo original:\n");
    for (int i = 0; i < size; i++){
        printf("numeros[%d]: %d\n", i, numeros[i]);
    }

    //cambiar el valor del primer elemento a 150

    for (int i = 0; i<size; i++){
        if (i==0){
            numeros[i]=150;
        }
    }
    //imprime el arreglo con las modificaciones

    printf("arreglo con modificaciones:\n");
    for(int i = 0; i<size; i++){
        printf("numeros[%d]=%d\n", i, numeros[i]);
    }
return 0;
}