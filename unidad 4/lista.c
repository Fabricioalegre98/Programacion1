#include <stdio.h> 

int main(void) 
{ 
    int i, n, c; 
    printf("Introduzca el numero de elementos de la lista: "); 
    scanf("%d", &n); 
    int lista[n]; 
    printf("Introduzca los elementos de la lista: "); 
    for (i = 0; i < n; i++) 
        scanf("%d", &lista[i]); 
    printf("Lista en orden ascendente: "); 
    for (i = 0; i < n; i++) 
        printf("%d ", lista[i]); 
    printf("\n"); 
    for (i = 0; i < n; i++) 
        printf("%d ", lista[i]); 
    c = lista[n - 1]; 
    for (i = n - 2; i >= 0; i--) 
        if (lista[i] > c) 
            c = lista[i]; 
    printf("\nEl elemento maximo es: %d", c); 
    return 0; 
}