#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define ARCH "c:\\bin.dat"
struct a{
   char nombre[10];
    int edad;
};
int main ()
{
        FILE *bin;
        struct a pers;
        int cant;
        system("cls"); 
    if ((bin=fopen(ARCH,"rb"))==NULL)
        printf("No se pudo abrir el archivo");
    while(!feof(bin))
{
    cant=fread(&pers,sizeof(pers),1,bin);
        if(cant!=1)
    {
        if(feof(bin))
        break;
        else
        {
            printf("Error al leer el archivo");
            return 1;
        }
        printf("No leyo el ultimo registro");
        break;
}
}
    printf("\n%s\t%d",pers.nombre,pers.edad);
    fclose(bin);
    getch();
    return 0;
}