#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"
#include <string.h>
#include "genero.h"
#include "time.h"
#include "movie.h"
#include "pedirDatos.h"

int main()
{
    int respuesta;
    LinkedList* peliculas = ll_newLinkedList();
    LinkedList* peliculasConRating = NULL;
    LinkedList* peliculasConGenero = NULL;
    LinkedList* generos = genero_newLista();
    srand(time(NULL));
    int seOrdeno = 0;
    int hayGeneros = 0;
    int hayRating = 0;
    int id=1;
    char path[50];
    int cantPeliculas = 0;

    do{
        cantPeliculas = ll_len(peliculas);
        hayGeneros = verificarGeneros(peliculas);
        hayRating = verificarRating(peliculas);

        switch(respuesta = pedirMenu()){
            case 1:
                if(pedirPath(path))
                    controller_loadFromText(path,peliculas,&id,generos);
            break;
            case 2:
                if(cantPeliculas > 0)
                    controller_printList(peliculas,generos);
            break;
            case 3:
                 if(cantPeliculas > 0 && (peliculasConRating = controller_setRating(peliculas))){
                    ll_deleteLinkedList(peliculas);
                    peliculas = peliculasConRating;
                    controller_printList(peliculas,generos);
                    hayRating = 1;
                 }

            break;
            case 4:
                if(cantPeliculas >0 && (peliculasConGenero = controller_setGenero(peliculas))){
                    ll_deleteLinkedList(peliculas);
                    peliculas = peliculasConGenero;
                    controller_printList(peliculas,generos);
                    hayGeneros = 1;
                }
            break;
            case 5:
                if(cantPeliculas >0 && hayGeneros)
                    controller_filterByGenero(peliculas,generos);
                else
                    printf("No hay generos asignados \n");
            break;
            case 6:
                if(cantPeliculas >0 && hayGeneros && hayRating)
                    seOrdeno = controller_sortByGeneroAndRating(peliculas,generos);
                else
                    printf("No hay generos/rating asignados \n");
            break;
            case 7:
                if(cantPeliculas >0 && seOrdeno && pedirPath(path))
                    controller_saveAsText(path,peliculas,generos);
                else
                    printf("Debe realizar primero el ordenamiento para guardar el archivo \n");
            break;
            case 8:
                printf("Saliendo...\n");
            break;
            default:
                printf("Opcion del menu erronea, vuelva a ingresar \n");
            break;
        }
        if(respuesta > 1 && respuesta<8 && cantPeliculas <= 0){
            printf("No hay peliculas cargadas \n");
        }
        system("pause");
        system("cls");
    }while(respuesta != 8);

    genero_deleteLista(generos);
    ll_deleteLinkedList(peliculas);
    ll_deleteLinkedList(generos);
    return 0;
}


