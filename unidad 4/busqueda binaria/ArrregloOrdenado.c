#include <stdio.h>

int main(){
    int arreglo[] = {3,7,15,20,25,31,40}; //arreglo Ordenado
    int n = sizeof(arreglo) / sizeof(arreglo[0]);
    int buscar, inicio = 0, fin = n-1, medio;
    int encontrado = 0;
    printf("ingrese el numero que quiere buscar: ");
    scanf("%d", &buscar);

    while ( inicio <= fin) {
        medio = ( inicio + fin) / 2;
    
    
        if (arreglo[medio]==buscar){
            printf("el numero se encuentra en la posicion %d\n", medio);
            encontrado =1;
            break;

            } else if (buscar<arreglo[medio]){
                fin = medio - 1;
            
            } else {
                inicio = medio + 1;
            }

    if (!encontrado){
     printf("no se encuentra el numero en el arreglo\n");
    }
}
return 0;
}


