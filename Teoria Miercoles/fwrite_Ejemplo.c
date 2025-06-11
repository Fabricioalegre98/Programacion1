#include <stdio.h>
#include <string.h>
/*
	Alumno: Alegre Fabricio
	DNI: 41517446
	Legajo: 30303
*/

int main() {
    FILE *parch;
    char texto[] = "Prueba de escritura";
    int cant, longi;

	
    parch = fopen("d:\\prueba.txt", "w");
    if (parch == NULL) {
        printf("\nEl archivo no puede ser abierto para escritura\n");
        return 1;
    }

    longi = strlen(texto);
    cant = fwrite(texto, sizeof(char), longi, parch);

    if (cant < longi) {
        printf("\nError al escribir el archivo\n");
    } else {
        printf("\nSe escribieron %d caracteres\n", cant);
    }

    fclose(parch);
	
	
    parch = fopen("d:\\prueba.txt", "r");
    if (parch == NULL) {
        printf("\nEl archivo no puede ser abierto para lectura\n");
        return 1;
    }

    printf("\nContenido del archivo:\n");

    char buffer[100];
    while (fgets(buffer, sizeof(buffer), parch) != NULL) {
        printf("%s", buffer);
	}
    fclose(parch);

    return 0;
}