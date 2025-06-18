#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Nodo {
    int dato;
    struct Nodo*siguiente;
} Nodo;

typedef struct Cola{
    Nodo* frente;
    Nodo* final;
} Cola;

void inicializarCola(Cola* cola){
    cola->frente = NULL;
    cola->final = NULL;
}

int estaVacia(Cola* cola){
    return cola->frente == NULL;
}

void encolar(Cola* c, int valor){
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->dato = valor;
    nuevo->siguiente = NULL;
    if (estaVacia(c)){
        c->frente = nuevo;
    } else {
        c->final->siguiente = nuevo;
    }
    c->final = nuevo;
}

int desencolar(Cola* c){
    if (estaVacia(c)) {
        printf("La cola esta vacia.\n");
        return -1; // Indicador de error
    }
    Nodo* temp = c->frente;
    int valor = temp->dato;
    c->frente = c->frente->siguiente;
    if (c->frente == NULL) {
        c->final = NULL; // Si la cola queda vacia, actualizamos el final
    }
    free(temp);
    return valor;   
}

void mostrarArreglo(int arr[], int n){
    printf ("Elementos del arreglo: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void ordenarArreglo(int arr[], int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    Cola c;
    inicializarCola(&c);
    int n, valor, contador=0;
    int arreglo[MAX];
 
    printf("Ingrese la cantidad de numeros a encolar: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &valor);
        encolar(&c, valor);
        arreglo[contador++] = valor;
    }

    if (contador == n) {
        printf("La cantidad de numeros ingresados coincide con la cantidad de numeros encolados.\n");
    }else {
        printf("La cantidad de numeros ingresados no coincide con la cantidad de numeros encolados.\n");
    }
// Desencolar los elementos y almacenarlos en el arreglo
    int i = 0;
    while (!estaVacia(&c)) {
        arreglo[i++] = desencolar(&c);
    }

    mostrarArreglo(arreglo, n);
    ordenarArreglo(arreglo, n);

    printf("Arreglo ordenado:\n");
    mostrarArreglo(arreglo, n);

    for (int i = 0; i < n; i++) {
        encolar(&c, arreglo[i]);
    }
    printf("Elementos desencolados de la cola ordenada:\n");
    while (!estaVacia(&c)) {
        printf("%d ", desencolar(&c));
    }
    printf("\n");

    return 0;
}
