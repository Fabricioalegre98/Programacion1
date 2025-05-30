#include <stdio.h>

// función que intenta cambiar el valor (por valor)
void pintar(int hoja) {
    hoja = 10; // Solo cambia la copia local
}

int main() {
    int miDibujo = 5;
    printf("Antes de pintar, miDibujo vale: %d\n", miDibujo);

    pintar(miDibujo); // Le paso solo el valor, no la dirección

    printf("Después de pintar, miDibujo vale: %d\n", miDibujo);

    return 0;
}

