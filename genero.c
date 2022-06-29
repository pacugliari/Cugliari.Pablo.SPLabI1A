#include "genero.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

eGenero* genero_new(){
	eGenero* nuevoGenero = (eGenero*) calloc(1,sizeof(eGenero));
    return nuevoGenero;
}


eGenero* genero_newParametros(int id,char* descripcion){
	eGenero* nuevoGenero = genero_new();
    if(nuevoGenero && descripcion ){
        if(!(genero_setId(nuevoGenero,id) && genero_setDescripcion(nuevoGenero,descripcion))){
        	genero_delete(nuevoGenero);
        	nuevoGenero = NULL;
           }
    }
    return nuevoGenero;
}

LinkedList* genero_newLista (){
	LinkedList* todoOk = ll_newLinkedList();
	eGenero* generoActual;

	if(todoOk){
        generoActual = genero_newParametros(0,"sin genero");
		if(generoActual)
			ll_add(todoOk,generoActual);
		generoActual = genero_newParametros(1,"Drama");
		if(generoActual)
			ll_add(todoOk,generoActual);
		generoActual = genero_newParametros(2,"Comedia");
		if(generoActual)
			ll_add(todoOk,generoActual);
		generoActual = genero_newParametros(3,"Accion");
		if(generoActual)
			ll_add(todoOk,generoActual);
        generoActual = genero_newParametros(4,"Terror");
		if(generoActual)
			ll_add(todoOk,generoActual);
	}

	return todoOk;
}

int genero_deleteLista(LinkedList* generos){
	int todoOk = 0;
	eGenero* generoActual;
	if(generos){
		for(int i=0;i<ll_len(generos);i++){
			generoActual = (eGenero*) ll_get(generos,i);
			genero_delete(generoActual);
		}
		ll_deleteLinkedList(generos);
		todoOk = 1;
	}
	return todoOk;
}

void genero_delete(eGenero* genero){
	free(genero);
}

int genero_setId(eGenero* this,int id){
    int todoOk = 0;
    if(this && id >= 0 && id <= 4 ){ //VALIDACION DE ID
    	this->id = id;
        todoOk = 1;
    }
    return todoOk;
}
int genero_getId(eGenero* this,int* id){
    int todoOk = 0;
    if(this && id){
        (*id) = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int genero_setDescripcion(eGenero* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion && strlen(descripcion) > 0 && strlen(descripcion) < 25){
        strcpy(this->descripcion,descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int genero_getDescripcion(eGenero* this,char* descripcion){
    int todoOk = 0;
    if(this && descripcion){
        strcpy(descripcion,this->descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int buscarGeneroPorDescripcion (LinkedList* generos,char* descripcion,int* pIndice){
    int todoOk = 0;
    eGenero* generoActual;

    if(generos&& pIndice){
        *pIndice = -1;
        for(int i=0;i<ll_len(generos);i++){
        	generoActual = (eGenero*) ll_get(generos,i);
            if(!strcmp(generoActual->descripcion,descripcion)){
                *pIndice = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarGeneroPorId (LinkedList* generos,int id,int* pIndice){
    int todoOk = 0;
    eGenero* generoActual;

    if(generos && pIndice){
    	(*pIndice) = -1;
        for(int i=0;i<ll_len(generos);i++){
        	generoActual = (eGenero*) ll_get(generos,i);
            if(generoActual->id == id){
                (*pIndice) = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarGeneros (LinkedList* generos){
    int todoOk = 0;
    eGenero* generoActual;

    if(generos){
        system("cls");
        printf("\n-------------------------------\n");
        printf("  ***LISTADO DE GENEROS***\n");
        printf("-------------------------------\n");
        printf("ID\tGenero\n");
        printf("-------------------------------\n");
        for(int i=0;i<ll_len(generos);i++){
            generoActual = (eGenero*) ll_get(generos,i);
            if(generoActual->id != 0){
                printf("%d\t%-10s\n",generoActual->id,generoActual->descripcion);
            }
        }
        printf("-------------------------------\n\n");
        todoOk= 1;
    }

    return todoOk;
}


int validarGenero (LinkedList* generos,int id){
    int todoOk = 0;
    int indice;
    if(generos){
    	buscarGeneroPorId (generos,id,&indice);
        if(indice != -1)
            todoOk = 1;
    }
    return todoOk;
}


int cargarDescripcionGenero (LinkedList* generos,int id,char descripcion[]){
    int todoOk = 0;
    int indice;
    eGenero* generoActual;

    if(generos && descripcion && buscarGeneroPorId(generos,id,&indice)){
    	generoActual = (eGenero*) ll_get(generos,indice);
        strcpy(descripcion,generoActual->descripcion);
        todoOk = 1;
    }
    return todoOk;
}

int pedirGenero (LinkedList* generos,int* id){
    int todoOk=0;
    if(generos && id){
    	listarGeneros(generos);
        printf("Ingrese el ID del genero: ");
        scanf("%d",id);
        fflush(stdin);

        while(id== 0 && !validarGenero(generos,*id)){
            printf("Error en la ID del genero.Vuelva a ingresar: ");
            scanf("%d",id);
            fflush(stdin);
        }
        todoOk = 1;
    }
    return todoOk;

}


