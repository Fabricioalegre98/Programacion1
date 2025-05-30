#include <stdio.h>
#include <string.h>

int main(){
// metodo de ordenamiento por seleccion

int arr[]={2, 9, 1, 5, 6};
int n = sizeof(arr) / sizeof (arr[0]);
int i, j, min_idx, temp;

    for (i = 0; i < n-1; i++){
        min_idx = i; // suponemos que el menor está en la posición i
        for (j = i+1; j < n; j++){
            if (arr[j] < arr[min_idx]){
                min_idx = j; // encontramos un número más chico
            }
        }
        // intercambiamos el menor encontrado con el primero de la parte no ordenada
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }   

    printf("arreglo ordenado: \n");
    for (i=0; i<n; i++){
        printf("%d ", arr[i]);
    }   
    return 0;
}
