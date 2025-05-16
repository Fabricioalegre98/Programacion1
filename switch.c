#include <stdio.h>
#include <stdlib.h>

int main() {
    int opcion, a, b;
    printf("Calculadora simple (switch)\n");
    printf("1. Sumar\n");
    printf("2. Restar\n");
    printf("3. Multiplicar\n");
    printf("4. Dividir\n");
    printf("5. Sumar varios numeros\n");
    printf("Elige una opcion: 1-5\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Introduce el primer numero: ");
            scanf("%d", &a);
            printf("Introduce el segundo numero: ");
            scanf("%d", &b);
            printf("El resultado es: %d\n", a + b);
            break;
        case 2:
            printf("Introduce el primer numero: ");
            scanf("%d", &a);
            printf("Introduce el segundo numero: ");
            scanf("%d", &b);
            printf("El resultado es: %d\n", a - b);
            break;
        case 3:
            printf("Introduce el primer numero: ");
            scanf("%d", &a);
            printf("Introduce el segundo numero: ");
            scanf("%d", &b);
            printf("El resultado es: %d\n", a * b);
            break;
        case 4:
            printf("Introduce el primer numero: ");
            scanf("%d", &a);
            printf("Introduce el segundo numero: ");
            scanf("%d", &b);
            if (b != 0) {
                printf("El resultado es: %d\n", a / b);
            } else {
                printf("No se puede dividir por cero.\n");
            }
            break;
        case 5: {
            int cantidad, numero, suma = 0;
            printf("¿Cuantos numeros quieres sumar?: ");
            scanf("%d", &cantidad);
            for (int i = 1; i <= cantidad; i++) {
                printf("Introduce el numero %d: ", i);
                scanf("%d", &numero);
                suma += numero;
            }
            printf("La suma total es: %d\n", suma);
            break;
        }
        default:
            printf("Opcion no valida.\n");
    }

    return 0;
}
