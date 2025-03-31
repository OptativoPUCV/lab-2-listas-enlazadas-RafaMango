#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList()
{ 
    List* L = (List*)malloc(sizeof(List));
    if(L == NULL) return NULL;
    L->head = NULL;
    L->tail = NULL;
    L->current = NULL;
    
    return L;
}

void * firstList(List * list)
{
    if(list->head == NULL)return NULL; 
    list->current = list->head; // apunta al primer elem
    return list->current->data; 
    //return NULL;
}

void * nextList(List * list)
{
    if(list->current == NULL || list->current->next == NULL )return NULL;
    //Siguiente del siguiente
    list->current = list->current->next;
    return list->current->data;
    //return NULL;
}

void * lastList(List * list)
{
    if(list->tail == NULL)return NULL;
    list->current = list->tail; //current dato actual, asigna el ultimo 
    return list->current->data;
    //return NULL;
}

void * prevList(List * list)
{
    if(list->current == NULL || list->current->prev == NULL)return NULL;
    list->current = list->current->prev;
    return list->current->data;
    //return NULL;
}

void pushFront(List * list, void * data) 
{
    if(list == NULL)return;
    Node * nuevoNodo = createNode(data); //Recerva memoria y crea nuevo nodo con el dato entregado
    nuevoNodo->next = list->head; //apunta al que antes era el primero
    nuevoNodo->prev = NULL; // no hay previo, este es el primer dato

    if(list->head != NULL) // no vacia 
    {
        list->head->prev = nuevoNodo; // anterior primer nodo apunta al nuevo
        
    }
    else //si esta vacia
    {
        list->tail = nuevoNodo; // nuevo tambien ultimo
    }
    list->head = nuevoNodo; // nuevo nodo asignado como primero
    
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) //agrega elemento oen posicion actual de la lista
{
    if(list->current == NULL)return; 
    Node* nuevoNodo = createNode(data); //memoria
    nuevoNodo->next = list->current->next; //asigna a prev el dato al siguiente nodo del actual
    nuevoNodo->prev = list->current; //asigna, conecta nodo al actual

    if(list->current->next != NULL)
    {
        list->current->next->prev = nuevoNodo;
    }
    //conexion current con nuevo nodo
    list->current->next = nuevoNodo;
    if(list->tail == list->current) //Si es que el dato actual es el ultimo dato(nodo)
    {
        list->tail = nuevoNodo;
    }
}

void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) 
{
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list)
{
    if(list == NULL || list->current == NULL)return NULL;
    Node* eliminar = list->current;

    if(eliminar->prev != NULL)
    {
        eliminar->prev->next = eliminar->next;
    }
    else
    {
        list->head = eliminar->next;
    }
    if(eliminar->next != NULL)
    {
        eliminar->next->prev = eliminar->prev;
    }
    else
    {
        list->tail = eliminar->prev;
    }
    list->current = eliminar->next;
    free(eliminar);
}
/***
    if(list->head == list->tail) //solo un nodo
    {
        free(list->current);
        list->head = list->tail = list->current = NULL;
        return dato;
    }
    if(list->current->prev != NULL) //existe (anterior)
    {
        list->current->prev->next = list->current->next;
    }
    else //actualizar nodo, si se elimina el primer nodo
    {
        list->head = list->current->next;
    }
    if(list->current->next != NULL) //existe (siguiente)
    {
        list->current->next->prev = list->current->prev;
    }
    else //actualizar nodo, si se elimina el ultimo nodo
    {
        list->tail = list->current->prev;
    }
    Node *siguienteNode = list->current->next;
    free(list->current);

    list->current = siguienteNode;
    return dato;
***/
    

void cleanList(List * list) 
{
    while (list->head != NULL) 
    {
        popFront(list);
    }
}