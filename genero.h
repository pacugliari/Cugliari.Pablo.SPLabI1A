#include "LinkedList.h"

#ifndef GENERO_H_INCLUDED
#define GENERO_H_INCLUDED

typedef struct{
    int id;
    char descripcion [25];
}eGenero;

#endif // GENERO_H_INCLUDED

//CONSTRUCTORES

/** \brief crea en memoria dinamica un estructura del tipo genero
 *
 * \return eGenero*,retorna la direccion de memoria del genero reservado o NULL
 *
 */
eGenero* genero_new();


/** \brief crea en memoria dinamica una estructura del tipo genero con los campos cargados segun los parametros
 *
 * \param id int, id a cargar en el campo id de la estructura
 * \param descripcion char*, descripcion a cargar en el campo descripcion de la estructura
 * \return eGenero*,retorna la direccion de memoria del genero reservado o NULL
 *
 */
eGenero* genero_newParametros(int id,char* descripcion);


/** \brief crea una lista de generos en memoria con valores ya definidos (sin genero,drama,accion,terror y comedia)
 *
 * \return LinkedList*,lista con los generos hardcodeados o NULL
 *
 */
LinkedList* genero_newLista ();

//DESTRUCTORES

/** \brief libera de memoria la lista de generos pasada por parametro
 *
 * \param generos LinkedList*, lista de generos
 * \return int, si se pudo liberar la lista retorna 1 sino 0
 *
 */
int genero_deleteLista(LinkedList* generos);


/** \brief libera de memoria el genero pasado por parametro
 *
 * \param genero eGenero*,genero a liberar de memoria
 * \return void
 *
 */
void genero_delete(eGenero* genero);

//SETTERS

/** \brief carga el parametro id en el campo id de la estructura del parametro
 *
 * \param this eGenero*,puntero a genero que se quiere carga el id
 * \param id int,id que se quiere cargar en el genero
 * \return int,si se cargo manera correcta 1 sino 0
 *
 */
int genero_setId(eGenero* this,int id);


/** \brief carga el parametro descripcion en el campo descripcion de la estructura del parametro
 *
 * \param this eGenero*,puntero a genero que se quiere cargar la descripcion
 * \param descripcion char*,descripcion que se quiere cargar en el genero
 * \return int,si se cargo de manera correcta 1 sino 0
 *
 */
int genero_setDescripcion(eGenero* this,char* descripcion);

//GETTERS

/** \brief carga en el parametro id el valor del campo id de la estructura del parametro
 *
 * \param this eGenero*,puntero a genero que se quiere obtener su id
 * \param id int*, puntero a variable que almacena el id de la estructura
 * \return int, si se obtuvo de manera correcta retorna 1 sino 0
 *
 */
int genero_getId(eGenero* this,int* id);


/** \brief carga en el parametro descripcion el valor del campo descripcion de la estructura  del parametro
 *
 * \param this eGenero*,puntero a genero que se quiere obtener su descripcion
 * \param descripcion char*,puntero a cadena donde se va almacenar la descripcion de la estructura
 * \return int si se obtuvo de manera correcta retorna 1 sino 0
 *
 */
int genero_getDescripcion(eGenero* this,char* descripcion);

//OTROS

/** \brief muestra por consola la lista de generos con sus campos, id y descripcion
 *
 * \param LinkedList*, lista de generos
 * \return si se mostro de manera correcta retorna 1 sino 0
 *
 */
int listarGeneros (LinkedList* generos);


/** \brief carga en el parametro descripcion el campo descripcion de la estructura cuya id coincide con el parametro id
 *
 * \param LinkedList*, lista de generos
 * \param int, id del genero que se quiere obtener su descripcion
 * \param char*,cadena donde se va almacenar la descripcion de la estructura
 * \return retorna 1 si se realizo de manera correcta sino 0
 *
 */
int cargarDescripcionGenero (LinkedList* generos,int id,char descripcion[]);


/** \brief busca en la lista de generos el que coincide con la id del parametro, su posicion en la lista la carga en el parametro indice
 *
 * \param LinkedList*,lista de generos
 * \param int, id del elemento que se quiere obtener su indice
 * \param int*, puntero a variable donde se va almacenar el indice buscado
 * \return retorna 1 si se realizo de manera correcta sino 0
 *
 */
int buscargeneroPorId (LinkedList* generos,int id,int* indice);


/** \brief busca en la lista de generos el que coincide con la descripcion del parametro, su posicion en la lista la carga en el parametro indice
 *
 * \param LinkedList*,lista generos
 * \param char*, descripcion del elemento que se quiere obtener su indice
 * \param int*, puntero a variable donde se va almacenar el indice buscado
 * \return retorna 1 si se realizo de manera correcta sino 0
 *
 */
int buscarGeneroPorDescripcion (LinkedList* generos,char* descripcion,int* indice);


/** \brief valida si la id del parametro pertenece algun genero de la lista
 *
 * \param LinkedList*,lista de generos
 * \param int, id que se quiere validar
 * \return si el id pertenece a la lista retorna 1 sino 0
 *
 */
int validarGenero (LinkedList* generos,int id);


/** \brief pide por consola al usuario que ingrese un id de genero valido
 *
 * \param LinkedList* generos,lista de generos
 * \param int* id, puntero a variable donde se almacena la id ingresada por el usuario
 * \return retorna 1 si se realizo de manera correcta sino 0
 *
 */
int pedirGenero (LinkedList* generos,int* id);
