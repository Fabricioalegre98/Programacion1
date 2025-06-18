#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50
#define MAX_APELLIDO 50
// Estructura para almacenar la información de un alumno
typedef struct {
    int dni;
    char nombre[MAX_NOMBRE];
    char apellido[MAX_APELLIDO];
    float nota;
} Alumno;
// Prototipos de funciones
void agregarAlumnos(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "ab");
    if (!f){
        printf("Error al abrir el archivo %s\n", archivoFacu);
        return;
    }
    Alumno nuevo;
    char seguir = 's';
    while (seguir == 's' || seguir == 'S') {
        printf("Ingrese el DNI del alumno: ");
        scanf("%d", &nuevo.dni);
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nuevo.nombre);
        printf("Ingrese el apellido del alumno: ");
        scanf("%s", nuevo.apellido);
        printf("Ingrese la nota del alumno: ");
        scanf("%f", &nuevo.nota);
        fwrite(&nuevo, sizeof(Alumno), 1, f);
        printf("¿Desea agregar otro alumno? (s/n): ");
        scanf(" %c", &seguir);
    }
    fclose(f);
}
// Función para mostrar el listado de alumnos
void mostrarListadoAlumnos(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "r");
    if (!f){
        printf("Error al abrir el archivo %s\n", archivoFacu);
        return;
    }
    Alumno a;
    while (fread(&a, sizeof(Alumno), 1, f)){
        printf("DNI: %d\n", a.dni);
        printf("Nombre: %s\n", a.nombre);
        printf("Apellido: %s\n", a.apellido);
        printf("Nota: %.2f\n", a.nota);
        printf("-------------------------\n");
    }
    fclose(f);
}

int contarAlumnos(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "rb");
    if (!f) return 0;
    int count = 0;
    Alumno a;
    while (fread(&a, sizeof(Alumno), 1, f)) count++;
    fclose(f);
    return count;
}

float promedioNotas(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "rb");
    if (!f) return 0.0;
    float suma = 0.0;
    int count = 0;
    Alumno a;
    while (fread(&a, sizeof(Alumno), 1, f)){
        suma += a.nota;
        count++;
    }
    fclose(f);
    return count > 0 ? suma / count : 0.0;
}

int contarAprobados(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "rb");
    if (!f) return 0;
    int count = 0;
    Alumno a;
    while (fread(&a, sizeof(Alumno), 1, f)){
        if (a.nota >= 6.0) count++;
    }
    fclose(f);
    return count;
}

int contarDesaprobados(const char *archivoFacu){
    FILE *f = fopen(archivoFacu, "rb");
    if (!f) return 0;
    int count = 0;
    Alumno a;
    while (fread(&a, sizeof(Alumno), 1, f)){
        if (a.nota < 6.0) count++;
    }
    fclose(f);
    return count;
}

int main(){
    const char *archivoFacu = "alumnos.dat";
    int opcion;
    do {

        printf("\n--- MENU ---\n");
        printf("1. Agregar alumnos\n");
        printf("2. Listado de alumnos\n");
        printf("3. Cantidad de alumnos\n");
        printf("4. Promedio de notas\n");
        printf("5. Cantidad de alumnos aprobados\n");
        printf("6. Cantidad de alumnos desaprobados\n");
        printf("7. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion){
            case 1:
                agregarAlumnos(archivoFacu);
                break;
            case 2:
                mostrarListadoAlumnos(archivoFacu);
                break;
            case 3:
                printf("Cantidad de alumnos: %d\n", contarAlumnos(archivoFacu));
                break;
            case 4:
                printf("Promedio de notas: %.2f\n", promedioNotas(archivoFacu));
                break;
            case 5:
                printf("Cantidad de alumnos aprobados: %d\n", contarAprobados(archivoFacu));
                break;
            case 6:
                printf("Cantidad de alumnos desaprobados: %d\n", contarDesaprobados(archivoFacu));
                break;
            case 7:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }

    } while (opcion != 7);

    return 0;
}