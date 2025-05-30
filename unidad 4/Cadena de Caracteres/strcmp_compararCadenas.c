#include <stdio.h>
#include <string.h>

int main(){

  char palabra1[50], palabra2[50];
    printf("Ingrese la primera palabra:");
    scanf("%s", palabra1);
    palabra1[strcspn(palabra1, "\n")]='\0'; // Eliminar el salto de línea

    printf("Ingrese la sgunda palabra:");
    scanf("%s", palabra2);
    palabra2[strcspn(palabra2, "\n")]='\0'; // Eliminar el salto de línea

    if (strcmp(palabra1, palabra2)==0){
        printf("las palabras son iguales\n");
    }else{
        printf("Las palabras son diferentes\n");
    }
    return 0;
}