#include <stdio.h>
#include <string.h>

struct persona {
    char nombre[20];
    int edad;
    float altura;
};
int main() {
struct persona p1; //creamos una variable del tipo persona
printf("Ingrese el nombre:"); //pedimos al usuario que ingrese los datos

fgets(p1.nombre, sizeof(p1.nombre), stdin); // leemos el nombre ingresado
p1.nombre[strcspn(p1.nombre, "\n")] ='\0'; // eliminamos el salto de linea
printf("Ingrese la edad:");
scanf("%d", &p1.edad);

printf("Ingrese la altura:");
scanf("%f",&p1.altura);

//mostramos los datos almacenados en la estructura 

printf(" Nombre: %s\n",p1.nombre);
printf(" Edad: %d\n",p1.edad);
printf(" Altura: %.f cm\n ",p1.altura);
return 0;
}