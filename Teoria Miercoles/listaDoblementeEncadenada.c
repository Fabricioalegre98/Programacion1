#include <stdio.h>
#include <stdlib.h> 

//funcion  para una lista doblemente encadenada
struct Nodo {
    int dato;
    struct Nodo* siguiente;
    struct Nodo* anterior;
};

struct Nodo* crearNodo(int valor) {
    struct Nodo* nuevo = (struct Nodo*) malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        exit(1);
    }
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    nuevo->anterior = NULL;
    return nuevo;
}

void agregarAlFinal(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        struct Nodo* actual = *cabeza;
        while (actual->siguiente != NULL) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

void insertarPrimero(struct Nodo** cabeza, int valor) {
    struct Nodo* nuevo = crearNodo(valor);
    nuevo->siguiente = *cabeza;
    if (*cabeza != NULL) {
        (*cabeza)->anterior = nuevo;
    }
    *cabeza = nuevo;
}

void imprimirLista(struct Nodo* cabeza) {
    printf("Lista: ");
    while (cabeza != NULL) {
        printf("%d -> ", cabeza->dato);
        cabeza = cabeza->siguiente;
    }
    printf("NULL\n");
}

// Nueva función: imprimir lista en reversa
void imprimirListaReversa(struct Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía\n");
        return;
    }
    // Ir al último nodo
    struct Nodo* actual = cabeza;
    while (actual->siguiente != NULL) {
        actual = actual->siguiente;
    }
    // Recorrer hacia atrás
    printf("Lista (reversa): ");
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->anterior;
    }
    printf("NULL\n");
}

void liberarLista(struct Nodo* cabeza) {
    struct Nodo* temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->siguiente;
        free(temp);
    }
}

int main() {
    struct Nodo* lista = NULL;
    int opcion, valor;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar nodo\n");
        printf("2. Mostrar lista\n");
        printf("3. Salir\n");
        printf("4. Insertar primero\n");
        printf("5. Mostrar lista en reversa\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                printf("Ingrese un valor entero: ");
                scanf("%d", &valor);
                agregarAlFinal(&lista, valor);
                break;
            case 2:
                imprimirLista(lista);
                break;
            case 3:
                liberarLista(lista);
                printf("Memoria liberada. Adios.\n");
                break;
            case 4:
                printf("Ingrese un valor entero: ");
                scanf("%d", &valor);
                insertarPrimero(&lista, valor);
                break;
            case 5:
                imprimirListaReversa(lista);
                break;
            default:
                printf("Opcion invalida.\n");
        }
    } while (opcion != 3);
    return 0;
}