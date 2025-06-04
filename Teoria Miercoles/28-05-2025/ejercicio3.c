#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LONGITUD 200 //define la dimension de la cadena

int contarVocales (const char *cadena);
void mostrarOracionesSeparadas(const char *cadena);
void mostrarOracionMasLarga(const char *cadena);

int main(){
    //1.definimos la cadena con el formato especificado

    char texto [LONGITUD]="hoy es miércoles. hoy es la clase de programación. estudio programación.";
    
    //2.Mostrar la longitud de la cadena usando strlen
    printf("la longitud de la cadena es: %lu\n\n", strlen(texto));

    //3.mostrar la cadena con una estructura repetitiva
    printf("texto almacenado:\n");
    for (int i=0; i<strlen(texto); i++){
        printf("%c", texto[i]);
    }
    printf("\n\n");

    //4.mostrar cada oracion en una linea separada
    mostrarOracionesSeparadas(texto);

    //5.contar cuantas vocales tiene el texto
    int numVocales = contarVocales(texto);
    printf("el texto tiene %d vocales\n\n", numVocales);

    //6.mostrar la oracion mas larga
    mostrarOracionMasLarga(texto);
    return 0;
}

//funcion para contar las vocales
int contarVocales(const char *cadena){
    int i, contador =0;
    const char *vocales = "aeiouAEIOU"; //vocales en minuscula y mayuscula

    for (i=0; cadena[i]!='\0'; i++){
        if (strchr(vocales, cadena[i])!=NULL){
            contador++;
        }
    }
    return contador;
}
//funcion para mostrar oraciones separadas por lineas en blanco

void mostrarOracionesSeparadas(const char *cadena){
    printf("texto separado por oraciones:\n");

    for (int i=0; cadena[i]!='\0'; i++){
        if (cadena[i] == '.'){
            printf("\n");
        }else if (cadena[i]=='_'){
            printf(" "); 
        }else{
            printf("%c", cadena[i]);
        }
    }
    printf("\n\n");
}
//funcion para encontrar la oracion mas larga y contar palabras 
void encontrarOracionMasLarga(const char *cadena){
    int maxPalabras = 0, palabrasActuales = 1;
    const char *oracionMasLarga = cadena;
    const char *inicioOracion = cadena;

    for (int i = 0; cadena[i]!= '\0'; i++){
        if (cadena[i]=='_'){
            palabrasActuales++;
        }
        if (cadena[i] == '.'){
            if (palabrasActuales > maxPalabras){
                maxPalabras = palabrasActuales;
                oracionMasLarga = inicioOracion;
            }
            palabrasActuales = 1;
            inicioOracion = cadena +i +1;
            }
        }

    }
    

//mostrar la oracion mas larga y su cantidad de palabras
printf("oracion mas larga:\n");
    for (int i=0; oracionMasLarga[i] !='\0' && oracionMasLarga{i}!= '.');
        if (oracionMasLarga[i]=='_'){
        printf(" ");
        } else {
        printf("%c", oracionMasLarga[i]);
        }
    }
    printf(".\n");
    printf("\nCantidad de palabras: %d\n\n", maxPalabras);
    printf("\n");
      