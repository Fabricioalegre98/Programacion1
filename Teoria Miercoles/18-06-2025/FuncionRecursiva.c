#include <stdio.h>

int sumaPares(int n) {
    if (n == 1)
        return 2;
    else
        return 2 * n + sumaPares(n - 1);
}

int main() {
    int n;
    printf("Ingrese la cantidad de numeros pares a sumar: ");
    scanf("%d", &n);
    printf("La suma de los %d primeros pares es: %d\n", n, sumaPares(n));
    return 0;
}