#include "LinkedList.h"

#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    int id;
    char titulo[50];
    int idGenero;
    float rating;
}eMovie;

#endif // MOVIE_H_INCLUDED


//Constructores

/** \brief reserva en memoria una estructura del tipo eMovie
 *
 * \return eMovie*,retorna la direccion en memoria reservada o NULL
 *
 */
eMovie* movie_new();


/** \brief reserva en memoria una estructura del tipo eMovie inicialiando sus campos con los parametros
 *
 * \param id int,id a cargar en el campo id de la estructura
 * \param titulo char*,titulo a cargar en el campo titulo de la estructura
 * \param genero int, id del genero a cargar en el campo idGenero de la estructura
 * \param rating float,rating a cargar en el campo rating de la estructura
 * \return eMovie*,retorna la direccion en memoria reservada o NULL
 *
 */
eMovie* movie_newParametros(int id,char* titulo,int genero,float rating);

/** \brief reserva en memoria una estructura del tipo eMovie inicialiando sus campos con los parametros del tipo string
 *
 * \param id char*,cadena id que se castea a int id y se le asigna al campo id de la estructura
 * \param titulo char*,titulo que se carga en el campo titulo de la estructura
 * \param genero char*,cadena genero que se castea a int idGenero y se le asigna al campo idGenero de la estructura
 * \param rating char*,cadena rating que se castea a float rating y se le asigna al campo rating de la estructura
 * \return eMovie*,retorna la direccion en memoria reservada o NULL
 *
 */
eMovie* movie_newParametrosString(char* id,char* titulo,char* genero,char* rating);


/** \brief reserva en memoria una estructura del tipo eMovie inicializando sus campos con los campos de la estructura del parametro
 *
 * \param eMovie, pelicula que contiene en sus campos los valores inicializadores
 * \return eMovie*, retorna la direccion en memoria reservada o NULL
 *
 */
eMovie* movie_newMovie (eMovie pelicula);

//Destructores

/** \brief libera de memoria la pelicula del parametro
 *
 * \param pelicula eMovie*,pelicula a liberar
 * \return void
 *
 */
void movie_delete(eMovie* pelicula);


/** \brief libera de memoria una lista de peliculas
 *
 * \param LinkedList*,lista de peliculas
 * \return
 *
 */
void movie_deleteLista (LinkedList* peliculas);

//Setters


/** \brief guarda el id del parametro en el campo id de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se le guarda el parametro id
 * \param id int,id a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_setId(eMovie* this,int id);

/** \brief guarda el titulo del parametro en el campo titulo de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se le guarda el parametro titulo
 * \param char*,titulo a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_setTitulo(eMovie* this,char* titulo);

/** \brief guarda el igGenero del parametro en el campo igGenero de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se le guarda el parametro igGenero
 * \param igGenero int,igGenero a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_setGenero(eMovie* this,int genero);

/** \brief guarda el rating del parametro en el campo rating de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se le guarda el parametro rating
 * \param rating int,rating a guardar
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_setRating(eMovie* this,float rating);

//Getters


/** \brief guarda en la variable id del parametro el campo id de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se quiere obtener su id
 * \param id int*,puntero a variable en donde se guarda el id
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_getId(eMovie* this,int* id);

/** \brief guarda en la variable titulo del parametro el campo titulo de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se quiere obtener su titulo
 * \param char*,puntero a variable en donde se guarda el titulo
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_getNombre(eMovie* this,char* titulo);


/** \brief guarda en la variable genero del parametro el campo genero de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se quiere obtener su genero
 * \param int*,puntero a variable en donde se guarda el genero
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_getApellido(eMovie* this,int* genero);

/** \brief guarda en la variable rating del parametro el campo rating de la estructura del parametro
 *
 * \param this eMovie*, pelicula que se quiere obtener su rating
 * \param float*,puntero a variable en donde se guarda el rating
 * \return int, se realizo todo correcto 1 sino 0
 *
 */
int movie_getCodigoVuelo(eMovie* this,float* rating);

//Comparadores


/** \brief compara el genero de la movie1 y movie 2 de los parametros si es mayor descripcion movie1 que 2 retorna 1, si movie2 es mayor a 1 retorna
-1 y si son iguales se compara su rating, si rating 1 es mayor a 2 retorna 1 , si es mayor el 2 retorna -1 si son iguales 0
 *
 * \param movie1 void*,puntero a void que contiene la pelicula 1
 * \param movie2 void*,puntero a void que contiene la pelicula 2
 * \return int retorna el valor de la comparacion
 *
 */
int movie_sortByGeneroAndRating(void* movie1,void* movie2);

//Filtradoras

/** \brief verifica si la pelicula del parametro es del genero drama
 *
 * \param void* ,puntero a void que contiene la pelicula a ver el genero
 * \return si es del genero drama retorna 1 sino 0
 *
 */
int filterMovieByDrama (void* movie);

/** \brief verifica si la pelicula del parametro es del genero comedia
 *
 * \param void* ,puntero a void que contiene la pelicula a ver el genero
 * \return si es del genero comedia retorna 1 sino 0
 *
 */
int filterMovieByComedia (void* movie);

/** \brief verifica si la pelicula del parametro es del genero accion
 *
 * \param void* ,puntero a void que contiene la pelicula a ver el genero
 * \return si es del genero accion retorna 1 sino 0
 *
 */
int filterMovieByAccion (void* movie);

/** \brief verifica si la pelicula del parametro es del genero terror
 *
 * \param void* ,puntero a void que contiene la pelicula a ver el genero
 * \return si es del genero terror retorna 1 sino 0
 *
 */
int filterMovieByTerror (void* movie);

//Otras


/** \brief imprime por consola la pelicula del parametro con todos sus campos, id,titulo,genero y rating
 *
 * \param pelicula eMovie*,pelicula a imprimir
 * \param generos LinkedList*,lista de generos
 * \return int, si se pudo mostrar de manera correcta 1 sino 0
 *
 */
int movie_print(eMovie* pelicula,LinkedList* generos);


/** \brief verifica si la lista de peliculas todas tienen su genero asignados
 *
 * \param LinkedList* peliculas, lista de peliculas
 * \return si alguna pelicula no tiene genero retorna 0 sino 1
 *
 */
int verificarGeneros (LinkedList* peliculas);

/** \brief verifica si la lista de peliculas todas tienen su rating asignados
 *
 * \param LinkedList* peliculas, lista de peliculas
 * \return si alguna pelicula no tiene rating retorna 0 sino 1
 *
 */
int verificarRating (LinkedList* peliculas);
