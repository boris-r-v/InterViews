/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct _Node	//Один елемент списка
{
    int num; 		//некоторые полезные данные
    struct _Node *prev;	//указатель на предыдущего
    struct _Node *next;	//указатель на последующего
} Node;

Node* node_create( )
{
    static int i = 0;
    Node* ret = (Node*) malloc(sizeof(Node) );
    ret -> num = ++i;
    ret->prev = ret->next = NULL;
}

#define T Node
#include "listAPI.h"

void work_with_node()
{
    printf (__FUNCTION__);
    NodeList* list = list_create();

    Node* n1 = node_create();
    Node* n2 = node_create();
    Node* n3 = node_create();
    Node* n4 = node_create();

    list_push_back( list, n1 );
    list_push_back( list, n2 );
    list_push_back( list, n3 );
    list_push_back( list, n4 );

    Node* n5 = node_create();
    Node* n6 = node_create();
    Node* n7 = node_create();
    Node* n8 = node_create();
    list_push_front( list, n5 );
    list_push_front( list, n6 );
    list_push_front( list, n7 );
    list_push_front( list, n8 );


    printf ( "size %lu\n", list->size );
    
    Node* tmp;
    for( tmp = list->head; tmp; tmp = tmp->next )
	printf( "%d\n", tmp->num );

    Node* gr = list_pop_front( list );
    printf ( "------------------------------\n" );
    printf ( "%d\n", gr->num );
    printf ( "------------------------------\n" );
    for( tmp = list->head; tmp; tmp = tmp->next )
	printf( "%d\n", tmp->num );



    gr = list_pop_back( list );
    printf ( "------------------------------\n" );
    printf ( "%d\n", gr->num );
    printf ( "------------------------------\n" );
    for( tmp = list->head; tmp; tmp = tmp->next )
	printf( "%d\n", tmp->num );
    printf ( "------------------------------\n" );
}


