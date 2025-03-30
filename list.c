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
}

void * nextList(List * list)
{
    if(list->current->next == NULL || list->current == NULL)return NULL;
    //Siguiende del siguiente
    list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list)
{
    list->current = list->tail;
    return list->current->data;
}

void * prevList(List * list) {

    list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) 
{

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
    
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}