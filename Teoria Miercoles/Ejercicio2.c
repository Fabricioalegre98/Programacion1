#include <stdio.h>

#define filas 4
#define columnas 4
//cargar una matriz de 4x4 y mostrar en pantalla 

    //funcion para cargar la matriz

void cargar_matriz (int matriz [filas][columnas]){//declaracion de la matriz 4x4
    int i,j;

        //entrada de datos con secuencia repetitiva
    printf("cargar los elementos de la matriz %dx%d:\n", filas, columnas);
     for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++){
            printf("elemento [%d][%d]: ",i, j);
            scanf(" %d", &matriz[i][j]); //leer el elemento
        }
    }
}
//funcion para mostrar la matriz
void mostrar_matriz (int matriz[filas][columnas]){

    int i, j;
    printf("\n La matriz es: \n");
    for (i=0; i<filas; i++){
        for (j=0; j<columnas; j++){
             printf("%d\t", matriz[i][j]);
        }
        printf("\n");//salto de linea
    }
   
}

int main(){
    //definicion de la matriz
    int matriz[filas][columnas]; 
    //llamada a la funcion de cargar
    cargar_matriz(matriz);

    //llamada a la funcion de mostrar
    mostrar_matriz(matriz);


return 0;
}