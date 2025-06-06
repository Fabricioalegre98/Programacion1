#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona{
    int dni;
    char nombre[50];
    char apellido[50];
    struct Persona *siguiente;
};

struct PersonaNueva{
    int dni;
    char nombre[50];
    char apellido[50];
};

void mostrarMenu(){
    printf("\nMenu de opciones:\n");
    printf(" 'i' - Insertar una persona\n");
    printf(" 'f' - Insertar al final\n");
    printf(" 'e' - Eliminar persona\n");
    printf(" 'm' - Mostrar listado\n");
    printf(" 'b' - Buscar Persona\n");
    printf(" 's' - Salir\n");
    printf(" Seleccione una opciÃ³n:"); 
}

void insertarAlInicio(struct Persona** cabeza, int dni, char nombre[50], char apellido[50]) {
    struct Persona* nuevo = (struct Persona*)malloc(sizeof(struct Persona)); 
    nuevo->dni = dni; 
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->apellido, apellido); 
    nuevo->siguiente = *cabeza; 
    *cabeza = nuevo;
}

void mostrarLista(struct Persona* cabeza) {
    printf("MOSTRAR LISTADO");
    while (cabeza != NULL) {
        printf("%d - %s %s", cabeza->dni, cabeza->nombre, cabeza->apellido);
        cabeza = cabeza->siguiente;
    }
}

struct PersonaNueva pedirDator(){
    printf("INGRESAR DATOS DE LA PERSONA\n");
    int dni;
    char nombre[50];
    char apellido[50];
    printf("\nIngrese DNI: ");
    scanf("%d", &dni);
    printf("Ingrese Nombre: ");
    scanf("%s", &nombre);
    printf("Ingrese Apellido: ");
    scanf("%s", &apellido);
    struct PersonaNueva nuevaPersona;
    nuevaPersona.dni = dni;
    strcpy(nuevaPersona.nombre, nombre);
    strcpy(nuevaPersona.apellido, apellido);
    return nuevaPersona;
}

void insertarAlFinal(struct Persona** cabeza, int dni, char nombre[50], char apellido[50]) {
    printf("INSERTAR PERSONA AL FINAL\n");
    struct Persona* nuevo = (struct Persona*)malloc(sizeof(struct Persona));
    nuevo->dni = dni;
    strcpy(nuevo->nombre, nombre);
    strcpy(nuevo->apellido, apellido);
    nuevo->siguiente = NULL; 
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct Persona* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente; 
        }
        actual->siguiente = nuevo;
    }
}

void buscarPersona(struct Persona* cabeza, int dni) {
    struct Persona* actual = cabeza;
    while (actual != NULL) {
        if (actual->dni == dni) {
            printf("Persona encontrada: %d - %s %s\n", actual->dni, actual->nombre, actual->apellido);
            return;
        }
        actual = actual->siguiente;
    }
    printf("Persona con DNI %d no encontrada.\n", dni);
}


int main(){
   struct Persona *inicio = NULL;
   char seguir = 's';
   char opcion = 'i';
   while(seguir == 's' || seguir == 'S'){
    mostrarMenu();
    scanf(" %c", &opcion);
    if(opcion == 'i'){
        struct PersonaNueva nuevaPersona = pedirDator();
        insertarAlInicio(&inicio, nuevaPersona.dni, nuevaPersona.nombre, nuevaPersona.apellido);
    }else if(opcion == 'f'){
        struct PersonaNueva nuevaPersona = pedirDator();
        insertarAlFinal(&inicio, nuevaPersona.dni, nuevaPersona.nombre, nuevaPersona.apellido);
    }else if(opcion == 'e'){
        printf("ELIMINAR PERSONA");
    }else if(opcion == 'm'){
        mostrarLista(inicio);
    }else if(opcion == 'b'){
        int dniBuscar;
        printf("Ingrese el DNI de la persona a buscar: ");
        scanf("%d", &dniBuscar);
        buscarPersona(inicio, dniBuscar);
    }else if(opcion == 's'){
        printf("SALIENDO DEL PROGRAMA");
        seguir = 'n';
    }else{
        printf("OPCION NO VALIDA, INTENTE NUEVAMENTE");
        continue;
    }
   }
return 0;
}