#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);


LinkedList* ll_newLinkedList(void)
{
    LinkedList* this= (LinkedList*) malloc(sizeof(LinkedList));

    if(this){
        this-> size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}


int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this){
        returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* returnAux = NULL;

    if(this && nodeIndex >=0 && ll_len(this) > nodeIndex){
        returnAux = this->pFirstNode;
        while(nodeIndex > 0){
            returnAux = returnAux->pNextNode;
            nodeIndex--;
        }
    }
    return returnAux;
}


Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNodo = NULL;
    Node* pNodoAnterior = NULL;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {

        pNodo = (Node*) malloc(sizeof(Node));
        if(pNodo != NULL)
        {
            pNodo->pElement = pElement;

            if( nodeIndex == 0)
            {
                pNodo->pNextNode = this->pFirstNode;
                this->pFirstNode = pNodo;
            }
            else
            {
                pNodoAnterior = getNode(this, nodeIndex-1);
                pNodo->pNextNode = pNodoAnterior->pNextNode;
                pNodoAnterior->pNextNode = pNodo;

            }
            this->size++;
            returnAux = 0 ;
        }
    }
    return returnAux;
}


int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}



int ll_add(LinkedList* this, void* pElement)
{

    return addNode(this,ll_len(this),pElement);
}


void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo = getNode(this,index);
    if(nodo){
        returnAux = nodo->pElement;
    }

    return returnAux;
}



int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo = getNode(this,index);
    if(nodo){
        nodo->pElement = pElement;
        returnAux = 0;
    }
    return returnAux;
}



int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* nodo = NULL;
    if(this && index >=0 && index< ll_len(this)){
        nodo = getNode(this,index);
        if(nodo == this->pFirstNode){ // PRIMER ELEMENTO
            this->pFirstNode = nodo->pNextNode;
        }else{
            Node* nodoAnterior = getNode(this,index-1);
            nodoAnterior->pNextNode = nodo->pNextNode;
        }
        this->size--;
        free(nodo);
        returnAux =  0;
    }

    return returnAux;
}



int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    if(this){
        while(this->pFirstNode){
             ll_remove(this,0);
        }
        returnAux = 0;
    }
    return returnAux;
}



int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this){
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}


int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int tam;
    if(this){
        tam = ll_len(this);
        for(int i=0;i<tam;i++){
            if( pElement == ll_get(this,i)){
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}


int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this){
        //OPERADOR TERNARIO
        //returnAux = this->pFirstNode == NULL ? 1: 0;
        if(ll_len(this))
            returnAux = 0;
        else
            returnAux = 1;
    }
    return returnAux;
}


int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this && !addNode(this,index,pElement)){
        returnAux =0 ;
    }
    return returnAux;
}



void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this && index >=0 && index < ll_len(this)){
        returnAux = ll_get(this,index);
        ll_remove(this,index);
    }
    return returnAux;
}



int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this){/*
        if(ll_indexOf(this,pElement) != -1){
            returnAux = 1;
        }else
            returnAux = 0;*/
        returnAux = ll_indexOf(this,pElement) >= 0 ? 1 : 0;
    }
    return returnAux;
}


int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int tam2;
    if(this && this2){
        returnAux = 1;
        tam2 = ll_len(this2);
        for(int i=0;i<tam2;i++){
            if(!ll_contains(this,ll_get(this2,i))){
                returnAux = 0;
                break;
            }
        }
    }
    return returnAux;
}


LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    if(this && from>=0 && from<ll_len(this) && to>from && to<=ll_len(this)){
        cloneArray = ll_newLinkedList();
        if(cloneArray){
            for(int i=from;i<to;i++){
                ll_add(cloneArray,ll_get(this,i));
            }
        }
    }
    return cloneArray;
}




LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    if(this){
        cloneArray = ll_subList(this,0,ll_len(this));
    }
    return cloneArray;
}



int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int comparacion;
    void* aux;
    void* elementoI;
    void* elementoJ;

    int tam;
    if(this && pFunc && (order == 1 || order == 0)){
        tam = ll_len(this);
        for(int i=0;i<tam-1;i++){
            for(int j=i+1;j<tam;j++){
                elementoI = ll_get(this,i);
                elementoJ = ll_get(this,j);
                comparacion = pFunc(elementoI,elementoJ);
                if((comparacion == 1 && order) || (comparacion ==-1 && !order)){
                    aux = elementoI;
                    ll_set(this,i,elementoJ);
                    ll_set(this,j,aux);
                }
            }
        }
        returnAux = 0;
    }
    return returnAux;

}




LinkedList* ll_filter(LinkedList* this,int (*pFunc)(void*)){
    LinkedList* listaFiltrada = NULL;
    int tam;
    void* elemento;
    if(this && pFunc){
        listaFiltrada = ll_newLinkedList();
        if(listaFiltrada){
            tam = ll_len(this);
            for(int i=0;i<tam;i++){
                elemento = ll_get(this,i);
                if(pFunc(elemento)){
                    ll_add(listaFiltrada,elemento);
                }

            }
        }
    }
    return listaFiltrada;
}


LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element)){
    LinkedList* listaMapeada = NULL;
    int tam;
    void* elemento;
    void* elementoMapeado;
    if(this && pFunc){
        listaMapeada = ll_newLinkedList();
        if(listaMapeada){
            tam = ll_len(this);
            for(int i=0;i<tam;i++){
                elemento = ll_get(this,i);
                elementoMapeado = pFunc(elemento);
                ll_add(listaMapeada,elementoMapeado);
            }
        }
    }
    return listaMapeada;
}
