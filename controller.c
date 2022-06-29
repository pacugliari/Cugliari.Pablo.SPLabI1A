#include "controller.h"
#include <stdio.h>
#include <stdlib.h>
#include "movie.h"
#include <ctype.h>
#include "parser.h"
#include "genero.h"
#include "pedirDatos.h"

int controller_loadFromText(char* path , LinkedList* peliculas,int* pId,LinkedList* generos)
{
	int todoOk =0;
	int contador=0;
	char confirmacion = 's';
	FILE* arch = fopen(path,"r");

	if(peliculas && generos){
		if(arch == NULL){
			printf("No se pudo abrir el archivo %s \n",path);

		}else{
			if(ll_len(peliculas) > 0){
				printf("Hay peliculas cargadas, desea sobrescribirlos ? s-n \n");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				movie_deleteLista(peliculas);
				contador = parser_PassengerFromText(arch,peliculas,pId,generos);
				printf("Cantidad de peliculas cargados desde el archivo de texto: %s es: %d \n",path,contador);
				todoOk=1;
			}else
				printf("Se canselo la carga de datos desde el archivo de texto \n");
		}
	}
	fclose(arch);
    return todoOk;
}


int controller_saveAsText(char* path , LinkedList* peliculas,LinkedList* generos)
{
	int todoOk = 0;
	char confirmacion = 's';
	eMovie* peliculaActual;
	char descripcionGenero[20];
	FILE* f = fopen(path,"r");
	if(peliculas){
		if(ll_len(peliculas) > 0){
			if(f != NULL){
				printf("El archivo ya existe, desea sobrescribirlo ? s-n: ");
				fflush(stdin);
				scanf("%c",&confirmacion);
				fflush(stdin);
				confirmacion = tolower(confirmacion);
			}
			if(confirmacion == 's'){
				fclose(f);
				FILE* f = fopen(path,"w");
				fprintf(f,"id,titulo,genero,rating\n");
				for(int i=0;i<ll_len(peliculas);i++){
					 peliculaActual = ll_get(peliculas,i);
					 cargarDescripcionGenero(generos,peliculaActual->idGenero,descripcionGenero);
					 fprintf(f,"%d,%s,%s,%f\n",peliculaActual->id,peliculaActual->titulo,descripcionGenero,peliculaActual->rating);
				}
				todoOk = 1;
				printf("Peliculas guardados de manera exitosa en el archivo de texto %s \n",path);
			}else
				printf("Se canselo el guardado en archivo texto \n");
		}else
			printf("No hay peliculas cargadas \n");
	}else
		printf("Error en los parametros de controller_saveAsText \n");

	fclose(f);
    return todoOk;
}


int controller_printList(LinkedList* peliculas,LinkedList* generos){
    int todoOk = 0;
    int tam;
    if(peliculas && generos){
        tam = ll_len(peliculas);
        system("cls");
        printf("\n-------------------------------------------------------------\n");
        printf("\t\t***LISTADO DE PELICULAS***\n");
        printf("-------------------------------------------------------------\n");
        printf("ID\tTitulo\t\t\t\tGenero\t\tRating\n");
        printf("-------------------------------------------------------------\n");
        for(int i=0;i<tam;i++){
            movie_print(ll_get(peliculas,i),generos);
        }
        printf("-------------------------------------------------------------\n\n");
        todoOk = 1;
    }

    return todoOk;
}

void* rating (void* peliculaSinRating){
    eMovie* peliculaConRating = (eMovie*) peliculaSinRating;
    int min = 10;
    int max = 100;
    if(peliculaConRating){
        peliculaConRating->rating = (float)((rand()%(max-min+1)) + min)/10;
    }
    return peliculaConRating;
}

void* genero (void* peliculaSinGenero){
    eMovie* peliculaConGenero = (eMovie*) peliculaSinGenero;
    int min = 1;
    int max = 4;
    if(peliculaConGenero){
        peliculaConGenero->idGenero =((rand()%(max-min+1)) + min);
    }
    return peliculaConGenero;
}

LinkedList* controller_setRating(LinkedList* peliculas){
    LinkedList* todoOk = NULL;
    if(peliculas){
         LinkedList* peliculasConRating = ll_map(peliculas,rating);
         if(peliculasConRating){
            todoOk = peliculasConRating;
         }
    }
    return todoOk;
}

LinkedList* controller_setGenero(LinkedList* peliculas){
    LinkedList* todoOk = NULL;
    if(peliculas){
         LinkedList* peliculasConGenero = ll_map(peliculas,genero);
         if(peliculasConGenero){
            todoOk = peliculasConGenero;
         }
    }
    return todoOk;
}

int controller_filterByGenero(LinkedList* peliculas,LinkedList* generos){
    int todoOk = 0;
    LinkedList* peliculasPorGenero = NULL;
    int idGenero;
    char path[50];

    if(peliculas && generos){
        pedirGenero(generos,&idGenero);
        switch(idGenero){
            case 1:
                peliculasPorGenero = ll_filter(peliculas,filterMovieByDrama);
            break;
            case 2:
                peliculasPorGenero = ll_filter(peliculas,filterMovieByComedia);
            break;
            case 3:
                peliculasPorGenero = ll_filter(peliculas,filterMovieByAccion);
            break;
            case 4:
                peliculasPorGenero = ll_filter(peliculas,filterMovieByTerror);
            break;
        }

        if(peliculasPorGenero){
            pedirPath(path);
            controller_saveAsText(path,peliculasPorGenero,generos);
            todoOk = 1;
        }



    }
    return todoOk;
}


int controller_sortByGeneroAndRating(LinkedList* peliculas, LinkedList* generos){
    int todoOk = 0;
    if(peliculas && generos){
        if(!ll_sort(peliculas,movie_sortByGeneroAndRating,0)){
            controller_printList(peliculas,generos);
            todoOk = 1;
        }

    }
    return todoOk;
}

