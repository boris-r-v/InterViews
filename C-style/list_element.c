/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct _Element	//Один елемент списка
{
    int num; 		//некоторые полезные данные
    struct _Element *prev;	//указатель на предыдущего
    struct _Element *next;	//указатель на последующего
} Element;

Element* element_create( )
{
    static int i = 0;
    Element* ret = (Element*) malloc(sizeof(Element) );
    ret -> num = ++i;
    ret->prev = ret->next = NULL;
}

#define T Element
#include "listAPI.h"

void work_with_element()
{
    CONT(Element,NodeList)* list = list_create();
    
    LIST_GET_TYPE(Element)*
    
    Element* n1 = element_create();
    Element* n2 = element_create();
    Element* n3 = element_create();
    Element* n4 = element_create();

    list_push_back( list, n1 );
    list_push_back( list, n2 );
    list_push_back( list, n3 );
    list_push_back( list, n4 );

    Element* n5 = element_create();
    Element* n6 = element_create();
    Element* n7 = element_create();
    Element* n8 = element_create();
    list_push_front( list, n5 );
    list_push_front( list, n6 );
    list_push_front( list, n7 );
    list_push_front( list, n8 );


    printf ( "size %lu\n", list->size );
    
    Element* tmp;
    for( tmp = list->head; tmp; tmp = tmp->next )
	printf( "%d\n", tmp->num );

    Element* gr = list_pop_front( list );
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


