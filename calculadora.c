#include <stdio.h>
#include <stdlib.h>


int main() {

    int opcion;
    printf("calculadora simple\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. DIvidir\n");
    printf("Elige una opcion: 1-4");
    scanf("%d", &opcion);

    if (opcion == 1) {
        int a, b;
        printf("Introduce el primer numero: ");
        scanf("%d", &a);
        printf("Introduce el segundo numero: ");
        scanf("%d", &b);
        printf("El resultado es: %d", a + b);
    } else if (opcion == 2) {
        int a, b;
        printf("Introduce el primer numero: ");
        scanf("%d", &a);
        printf("Introduce el segundo numero: ");
        scanf("%d", &b);
        printf("El resultado es: %d", a - b);
    } else if (opcion == 3) {
        int a, b;
        printf("Introduce el primer numero: ");
        scanf("%d", &a);
        printf("Introduce el segundo numero: ");
        scanf("%d", &b);
        printf("El resultado es: %d", a * b);
    } else if (opcion == 4) {
        int a, b;
        printf("Introduce el primer numero: ");
        scanf("%d", &a);
        printf("Introduce el segundo numero: ");
        scanf("%d", &b);
        if (b != 0) {
            printf("El resultado es: %d", a / b);
        } else {
            printf("No se puede dividir por cero.\n");
        }
    } else {
        printf("Opcion no valida.\n");
    }

    return 0;
}