#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED



#endif // PARSER_H_INCLUDED


/** \brief lee desde el puntero a archivo las peliculas validando su estructura y las carga en la LinkedList
 *
 * \param pFile FILE*,puntero a archivo donde se encuentran en formato texto
 * \param peliculas LinkedList*,lista de peliculas
 * \param pId int*,puntero a variable que lleva el control del id, guarda el mayor id que se lee del archivo +1
 * \param generos LinkedList*,lista de generos
 * \return int, retorna la cantidad de peliculas leidas con exito
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* peliculas,int* pId,LinkedList* generos);


/** \brief valida si la cadena del parametro es valida, se usa para validar el titulo de la pelicula
 *
 * \param cadena char*,cadena a validar
 * \return int, si es valida 1 sino 0
 *
 */
int esCadenaValida(char* cadena);
