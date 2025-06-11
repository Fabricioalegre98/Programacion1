#include <stdio.h>
#include <stdlib.h>

int main() {
    int *lista;
    int n, i;

    printf("Ingrese el numero de elementos de la lista: ");
    scanf("%d", &n);

    // Reservar memoria para n enteros
    lista = (int *)malloc(n * sizeof(int));
    if (lista == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    // Leer los elementos de la lista
    for (i = 0; i < n; i++) {
        printf("Ingrese el elemento %d: ", i + 1);
        scanf("%d", &lista[i]);
    }

    // Imprimir los elementos de la lista
    printf("Los elementos de la lista son:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    // Liberar la memoria reservada
    free(lista);

    return 0;

}

