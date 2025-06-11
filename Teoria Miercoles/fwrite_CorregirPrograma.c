#include <stdio.h>
#include <conio.h>
#define ARCH "c:\\\\bin.dat"

struct a {
    char nombre[10];
    int edad;
};

int main() {
    FILE *bin;
    struct a pers;
    int terminar = 0;
    clrscr();
    printf("\nSe va a generar por primera vez el archivo\n");
    if ((bin = fopen(ARCH, "wb")) == NULL) {
        printf("El archivo no puede ser abierto\n");
        return 1;
    }

    do {
        printf("\nIngrese el nombre: ");
        fflush(stdin); 
        fgets(pers.nombre, sizeof(pers.nombre), stdin);
        
        size_t len = strlen(pers.nombre);
        if (len > 0 && pers.nombre[len - 1] == '\n') {
            pers.nombre[len - 1] = '\0';
        }
        printf("Ingrese la edad: ");
        scanf("%d", &pers.edad);
        fflush(stdin); 
        fwrite(&pers, sizeof(pers), 1, bin);
        printf("\nPresione '1' para terminar o cualquier otra tecla para continuar: ");
        terminar = getche();
    } while (terminar != '1');

    fclose(bin);
    return 0;
}