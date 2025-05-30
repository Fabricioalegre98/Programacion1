#include <stdio.h>

//funcion pasaje por referencia

void pintar(int *hoja) {
    *hoja = 10; // Modifica el valor de la variable a la que apunta hoja
}

int main(){

int miDibujo = 5; // Esta variable miDibujo es global
printf("antes de pintar, mi dibujo vale: %d\n", miDibujo); // Imprime el valor antes de llamar a la función
pintar(&miDibujo); // Llamada a la funcion pintar

printf("despues de pintar mi dibujo vale: %d\n", miDibujo);

}