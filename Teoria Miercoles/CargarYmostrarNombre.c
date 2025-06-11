#include<stdio.h>
#include<string.h>
#include<conio.h>
#define a "d:\\arch2.dat"

/*
	Alumno: Alegre Fabricio
	DNI: 41517446
	Legajo: 30303
*/


int main()
{
	
	
	FILE *arch2;
	char nombre[100];
	int i,x;
	
	if ((arch2=fopen(a,"w"))==NULL)
			printf("No se pudo abrir el archivo");
	
	printf("ingrese 5 nombres separarados por puntos\n");
	scanf("%s",&nombre);
	
	fwrite(&nombre,sizeof(nombre),1,arch2);
	
	fclose(arch2);

	
	if ((arch2=fopen(a,"r"))==NULL){
		printf("No se pudo abrir el archivo");
	}
	
	fread(&nombre,sizeof(nombre),1,arch2);
	
	x=strlen(nombre);
	
	for(i=0;i<x;i++){
		if(nombre[i]=='.') printf("\n");
		else{
		printf("%c",nombre[i]);
		}
	}
	
	fclose(arch2);
	getch();


return 0;
}
