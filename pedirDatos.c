#include "pedirDatos.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int pedirMenu(){
    int respuesta;
    printf("----------------------------\n");
    printf("1) Cargar archivo \n");
    printf("2) Imprimir lista \n");
    printf("3) Asignar rating \n");
    printf("4) Asignar genero \n");
    printf("5) Filtrar por genero \n");
    printf("6) Ordenar peliculas \n");
    printf("7) Guardar peliculas: \n");
    printf("8) Salir \n");
    printf("----------------------------\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d",&respuesta);
    fflush(stdin);
    printf("----------------------------\n");

    return respuesta;
}


int pedirPath(char* path){
	int todoOk = 0;
	char pathAux [30];
	if(path){
		 path[0]='\0';
		 printf("Ingrese el Path: ");
		 fflush(stdin);
		 gets(pathAux);
		 fflush(stdin);
		 while(strlen(pathAux) <= 0 || strlen(pathAux) >= 20){
			 printf("Ingrese un Path mas corto/largo: ");
			 fflush(stdin);
			 gets(pathAux);
			 fflush(stdin);
		 }
		 strcat(path,pathAux);
		 todoOk = 1;
	}
     printf("----------------------------\n");
	 return todoOk;
}
