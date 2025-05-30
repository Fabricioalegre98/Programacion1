#include <stdio.h>
#include <string.h>

int main(){
    // metodo de ordenamiento por inserción

    inr arr []={2, 9, 1, 5, 6};
    int n = sizeof(arr) / sizeof (arr[o]);
    int i, j, key;

    for (i=1; i<n; i++){
        key = arr[i];
        j = i -1;
        while (j >=0 && arr [j]> key){
            arr[j+1]= arr[j]; // movemos el elemento hacia la derecha
            j = j -1;
        }
        arr[j+1] = key; // insertamos el elemento en su posición correcta
    }
}

printf("arreglo ordenado: \n");
for (i=0; i<n; i++){
    printf("%d")
}