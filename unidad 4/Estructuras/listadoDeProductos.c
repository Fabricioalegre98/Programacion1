#include <stdio.h>
#include <string.h>

struct Producto {
    char nombre[50];
    float precio;
    int cantidad;
};

int main() {
    struct Producto productos[5];
    int i;

    // Ingreso de datos
    for (i = 0; i < 5; i++) {
        printf("Producto %d:\n", i + 1);
        printf("Nombre: ");
        fgets(productos[i].nombre, sizeof(productos[i].nombre), stdin);
        productos[i].nombre[strcspn(productos[i].nombre, "\n")] = '\0';

        printf("Precio: ");
        scanf("%f", &productos[i].precio);

        printf("Cantidad: ");
        scanf("%d", &productos[i].cantidad);

        getchar(); // Limpiar el salto de línea pendiente
    }

    // Mostrar listado
    printf("\nListado de productos y valor total en stock:\n");
    for (i = 0; i < 5; i++) {
        float total = productos[i].precio * productos[i].cantidad;
        printf("Producto: %s | Valor total en stock: $%.2f\n", productos[i].nombre, total);
    }

    return 0;
}