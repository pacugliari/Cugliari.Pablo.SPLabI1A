#include "parser.h"
#include "genero.h"
#include "movie.h"
#include <string.h>


int esCadenaValida(char* cadena){
	int todoOk = 1;
	if(cadena){
		char cadenaAux [strlen(cadena)+1];
		strcpy(cadenaAux,cadena);
		strlwr(cadenaAux);
		for(int i=0;i<strlen(cadenaAux);i++){
			if((cadenaAux[i] < 97 || cadenaAux[i] > 122) && (cadenaAux[i] <'0' || cadenaAux[i]>'9')&& cadenaAux[i] != ' ' && cadenaAux[i] != '-' && cadenaAux[i] != '.'){
				todoOk=0;
				break;
			}
		}

	}
	return todoOk;
}

int parser_PassengerFromText(FILE* pFile , LinkedList* peliculas,int* pId,LinkedList* generos){
	int datosLeidos,datosCargados=0;
	char buffer [4][50];
    int indiceGenero;
    eGenero* auxGenero;
    eMovie* peliculaNueva = NULL;
    int mayorId = 0;
    int esPrimero = 1;
    char encabezado[]={"id,titulo,genero,rating"};
    char comprobacion[strlen(encabezado)+1];
    fgets(comprobacion,strlen(encabezado)+1,pFile);

    if(!strcmp(comprobacion,"id,titulo,genero,rating")){
    	do{
			datosLeidos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
			buscarGeneroPorDescripcion(generos,buffer[2],&indiceGenero);

			if(datosLeidos==4 && esCadenaValida(buffer[1])  && indiceGenero != -1){
				auxGenero = (eGenero*) ll_get(generos,indiceGenero);
				peliculaNueva = movie_newParametros(atoi(buffer[0]),buffer[1],auxGenero->id,atof(buffer[3]));
				if(peliculaNueva){
					if(peliculaNueva->id > mayorId || esPrimero){
						mayorId = peliculaNueva->id;
						esPrimero = 0;
					}
					ll_add(peliculas,peliculaNueva);
					datosCargados++;
				}
			}
		}while(!feof(pFile));

		(*pId) = mayorId +1;
    }else{
    	printf("Error esta intentando abrir un archivo binario o error en el encabezado del archivo \n");
    	printf("Formato de encabezado: id,titulo,genero,rating \n");
    }

	return datosCargados;

}
