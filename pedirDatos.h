#ifndef PEDIRDATOS_H_INCLUDED
#define PEDIRDATOS_H_INCLUDED



#endif // PEDIRDATOS_H_INCLUDED


/** \brief pide por consola al usuario una opcion del menu general
 *
 * \return int, retorna el valor ingresado por el usuario
 *
 */
int pedirMenu();



/** \brief pide por consola al usuario un path valido
 *
 * \param path char*,cadena donde se almacena el path ingreado
 * \return int, si se realizo de manera correcta 1 sino 0
 *
 */
int pedirPath(char* path);
