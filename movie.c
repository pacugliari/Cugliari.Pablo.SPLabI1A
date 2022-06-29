#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genero.h"
#include <ctype.h>

eMovie* movie_new(){
	eMovie* nuevaPelicula = (eMovie*) calloc(1,sizeof(eMovie));
    return nuevaPelicula;
}


eMovie* movie_newParametros(int id,char* titulo,int idGenero,float rating){
	eMovie* nuevaPelicula = movie_new();
    if(nuevaPelicula && titulo){
        if(!(movie_setId(nuevaPelicula,id) &&
        	 movie_setTitulo(nuevaPelicula,titulo) &&
			 movie_setGenero(nuevaPelicula,idGenero) &&
			 movie_setRating(nuevaPelicula,rating))){
        		movie_delete(nuevaPelicula);
                nuevaPelicula = NULL;
           }
    }
    return nuevaPelicula;
}

eMovie* movie_newParametrosString(char* id,char* titulo,char* idGenero,char* rating){
	return movie_newParametros(atoi(id),titulo,atoi(idGenero),atof(rating));
}

eMovie* movie_newMovie (eMovie pasajero){
    return movie_newParametros(pasajero.id,pasajero.titulo,pasajero.idGenero,pasajero.rating);
}


void movie_delete(eMovie* pelicula){
	free(pelicula);
}

void movie_deleteLista (LinkedList* peliculas){
    	int cursor = 0;
        eMovie* peliculaActual;
        int tamanioLista = ll_len(peliculas);
         while( tamanioLista > cursor){
             peliculaActual = ll_get(peliculas,cursor);
             movie_delete(peliculaActual);
             cursor++;
         }
         ll_clear(peliculas);
        printf("Se limpiaron %d peliculas de un total de %d cargadas en la lista \n",cursor,tamanioLista);
}



int movie_setId(eMovie* this,int id){
    int todoOk = 0;
    if(this && id >= 1 && id <= 9999 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int movie_getId(eMovie* this,int* id){
    int todoOk = 0;
    if(this && id){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int movie_setTitulo(eMovie* this,char* titulo){
    int todoOk = 0;
    if(this && titulo && strlen(titulo) > 1 && strlen(titulo) < 50){ //VALIDAR NOMBRE
        strcpy(this->titulo,titulo);
        strlwr(this->titulo);
        this->titulo[0] = toupper(this->titulo[0]);
        todoOk = 1;
    }
    return todoOk;
}

int movie_getTitulo(eMovie* this,char* titulo){
    int todoOk = 0;
    if(this && titulo){
        strcpy(titulo,this->titulo);
        todoOk = 1;
    }
    return todoOk;
}

int movie_setGenero(eMovie* this,int idGenero){
    int todoOk = 0;
    if(this){ //VALIDACION DE GENERO
    	this->idGenero = idGenero;
        todoOk = 1;
    }
    return todoOk;
}
int movie_getGenero(eMovie* this,int* idGenero){
    int todoOk = 0;
    if(this && idGenero){
        (*idGenero) = this->idGenero;
        todoOk = 1;
    }
    return todoOk;
}

int movie_setRating(eMovie* this,float rating){
    int todoOk = 0;
    if(this && rating >= 0 && rating <= 10){ //VALIDACION DE RATING
    	this->rating = rating;
        todoOk = 1;
    }
    return todoOk;
}
int movie_getRating(eMovie* this,int* rating){
    int todoOk = 0;
    if(this && rating){
        (*rating) = this->rating;
        todoOk = 1;
    }
    return todoOk;
}

int movie_print(eMovie* pelicula,LinkedList* generos){
    int todoOk = 0;
    char descripcionGenero[20];

    if(pelicula && generos){
        cargarDescripcionGenero(generos,pelicula->idGenero,descripcionGenero);
        printf("%d\t%-25s\t%-10s\t%.1f\n",pelicula->id,pelicula->titulo,descripcionGenero,pelicula->rating);
        todoOk= 1;
    }

    return todoOk;
}

int filterMovieByDrama (void* movie){
    int todoOk = 0;
    if(movie){
        eMovie* pelicula = (eMovie*) movie;
        if(pelicula->idGenero == 1){
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterMovieByComedia (void* movie){
    int todoOk = 0;
    if(movie){
        eMovie* pelicula = (eMovie*) movie;
        if(pelicula->idGenero == 2){
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterMovieByAccion (void* movie){
    int todoOk = 0;
    if(movie){
        eMovie* pelicula = (eMovie*) movie;
        if(pelicula->idGenero == 3){
            todoOk = 1;
        }
    }
    return todoOk;
}

int filterMovieByTerror (void* movie){
    int todoOk = 0;
    if(movie){
        eMovie* pelicula = (eMovie*) movie;
        if(pelicula->idGenero == 4){
            todoOk = 1;
        }
    }
    return todoOk;
}

int movie_sortByGeneroAndRating(void* movie1,void* movie2){
    int retorno = 0;
    eMovie* x;
    eMovie* y;
    char genero1[20];
    char genero2[20];
    LinkedList* generos = genero_newLista();

    if(movie1 && movie2 && generos){
        x = (eMovie*)movie1;
        y = (eMovie*)movie2;
        cargarDescripcionGenero(generos,x->idGenero,genero1);
        cargarDescripcionGenero(generos,y->idGenero,genero2);
        retorno = strcmp(genero1,genero2);
        if(retorno == 0){
            if(x->rating > y->rating){
                retorno = 1;
            }else if (x->rating < y->rating)
                retorno = -1;
        }
    }

    genero_deleteLista(generos);
    return retorno;
}

int verificarGeneros (LinkedList* peliculas){
    int todoOk = 1;
    int tam;
    eMovie* peliculaActual;
    if(peliculas){
        tam = ll_len(peliculas);
        for(int i=0;i<tam;i++){
            peliculaActual = ll_get(peliculas,i);
            if(peliculaActual->idGenero == 0){//ID DE SIN GENERO
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;
}


int verificarRating (LinkedList* peliculas){
    int todoOk = 1;
    int tam;
    eMovie* peliculaActual;
    if(peliculas){
        tam = ll_len(peliculas);
        for(int i=0;i<tam;i++){
            peliculaActual = ll_get(peliculas,i);
            if(peliculaActual->rating == 0){
                todoOk = 0;
                break;
            }
        }
    }
    return todoOk;
}
