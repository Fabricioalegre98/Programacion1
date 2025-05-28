#include <stdio.h>

int main() {
    // Ejemplo de uso de if-else con do-while
char tipo_reparacion;
    do{
printf("seleccione tipo de reparacion:\n");
printf("a.reparacion de software\n");
printf("b.reparacion de harware\n");
printf("c.matenimiento preventivo\n");
printf("x.salir\n");
scanf("%c",&tipo_reparacion);


if (tipo_reparacion == 'a') {
    printf("reparacion sofware\n precio:$5000\n");
} else if (tipo_reparacion == 'b') {
    printf("reparacion hardware\n precio:$6000\n");
} else if (tipo_reparacion == 'c') {
    printf("mantenimiento preventivo\n precio:$10000\n");
} else if (tipo_reparacion == 'x') {
    printf("salir\n");
    break;
} else {
    printf("opcion no valida\n");
}

return 0;
}

