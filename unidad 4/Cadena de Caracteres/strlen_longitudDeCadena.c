#include <stdio.h>
#include <string.h>

int main() {
    char texto[100];

    printf("Ingresa una palabra o frase: ");
    fgets(texto, sizeof(texto), stdin);

    // Eliminar el salto de línea si existe
    texto[strcspn(texto, "\n")] = '\0';

    printf("La cantidad de caracteres es: %lu\n", strlen(texto));

    return 0;
}