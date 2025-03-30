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
    return list->current->data; // devulve el dato del nodo que apunta al dato actual de la lista
    //return NULL;
}

void * nextList(List * list)// ERROR EN ESTA FUNCION 
{
    if(list == NULL || list->current == NULL || list->current->next == NULL )return NULL;
    //Siguiende del siguiente
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

void * prevList(List * list) {

    if(list->current == NULL || list->current->prev == NULL)return NULL;
    list->current = list->current->prev;
    return list->current->data;
    //return NULL;
}

void pushFront(List * list, void * data) 
{
    if(list == NULL)return;
    Node * nuevoNodo = createNode(data);
    nuevoNodo->next = list->head;
    nuevoNodo->prev = NULL;

    if(list->head != NULL)
    {
        list->head->prev = nuevoNodo;
        
    }
    else
    {
        list->tail = nuevoNodo;
    }
    list->head = nuevoNodo;
    if(list->head->next != NULL)
    {
        list->head->next->prev = list->head;
    }
    
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) //agrega elemento oen posicion actual de la lista
{
    void nuevo = list->current;
    if(list->current == NULL)return; 
    Node* nuevoNodo = createNode(data); //memoria
    nuevoNodo->next = nuevo->next; //asigna a prev el dato al siguiente nodo del actual
    nuevoNodo->prev = nuevo; //asigna, conecta nodo al actual

    if(nuevo->next != NULL){
        nuevo->next->prev = nuevoNodo;
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
    
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}