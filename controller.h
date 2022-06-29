#include "LinkedList.h"

#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED



/** \brief carga desde un archivo que se encuentra en el path en un LinkedList
 *
 * \param path char*,cadena con el path donde se encuentra el archivo
 * \param peliculas LinkedList*,lista de peliculas
 * \param pId int*,puntero a id para actualizar con el mayor id del archivo a cargar
 * \param generos LinkedList*,lista de generos
 * \return int si el archivo se pudo cargar en la lista retorna 1 sino 0
 *
 */
int controller_loadFromText(char* path , LinkedList* peliculas,int* pId,LinkedList* generos);


/** \brief guarda los datos del LinkedList en un archivo de texto en la direccion path
 *
 * \param path char*,cadena con el path donde se guarda el archivo
 * \param peliculas LinkedList*,lista de peliculas
 * \param generos LinkedList*,lista de generos
 * \return int si el archivo se pudo guardar retorna 1 sino 0
 *
 */
int controller_saveAsText(char* path , LinkedList* peliculas,LinkedList* generos);


/** \brief imprime por consola la lista peliculas con todos sus campos, id,titulo,genero y rating
 *
 * \param peliculas LinkedList*,lista de peliculas
 * \param generos LinkedList*,lista de generos
 * \return int, si se pudo imprimir la lista retorna 1 sino 0
 *
 */
int controller_printList(LinkedList* peliculas,LinkedList* generos);


/** \brief asigna a cada pelicula de la lista un genero aleatorio (drama,comedia,accion o terror)
 *
 * \param peliculas LinkedList*,lista de peliculas
 * \return LinkedList*, retorna una nueva lista con los generos cargados sino NULL
 *
 */
LinkedList* controller_setGenero(LinkedList* peliculas);

/** \brief asigna a cada pelicula de la lista un rating aleatorio entre 1 y 10 con 1 decimal
 *
 * \param peliculas LinkedList*,lista de peliculas
 * \return LinkedList*,retorna una nueva lista con los rating cargados sino NULL
 *
 */
LinkedList* controller_setRating(LinkedList* peliculas);


/** \brief guarda en un archivo de texto las peliculas filtradas por genero seleccionado por el usuario
 *
 * \param peliculas LinkedList*,lista de peliculas
 * \param generos LinkedList*,lista de generos
 * \return int, si se pudo guardar el archivo retorna 1 sino 0
 *
 */
int controller_filterByGenero(LinkedList* peliculas,LinkedList* generos);


/** \brief ordena la lista de peliculas por genero y rating descendente y las muestra por pantalla
 *
 * \param peliculas LinkedList*,lista de peliculas
 * \param generos LinkedList*,lista de generos
 * \return int,si se pudo ordenar y mostrar retorna 1 sino 0
 *
 */
int controller_sortByGeneroAndRating(LinkedList* peliculas, LinkedList* generos);
