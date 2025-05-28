#include <stdio.h>

int main(){

    int matriz[3][3] ={
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int fila = 0; fila < 3; fila++){
        for (int columna = 0; columna < 3; columna++){
            printf("%d ", matriz[fila][columna]);
        }
        printf("\n");
    }
    
    return 0;
}