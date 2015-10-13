/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/

/*
Нужет АPI для работы со связкным списком но могущий работать с разными структурами типа std::list
Раз хотят: то реализация на макросах С.

Типовой двухвязный список со вставкой и удалением по концам списка выглядит так:
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


typedef struct _NodeList //сам список
{
    size_t size;	//кол-во элементов в списке
    Node* head;		//
    Node* tail;
} NodeList;

NodeList* list_create( )
{
    NodeList* list = (NodeList*) malloc(sizeof(NodeList) );
    list -> size = 0;
    list -> head = list->tail = NULL;
    return list;
}

void list_delete( NodeList* _list )
{
    Node *head = _list -> head;
    Node *next = NULL;
    while( head )
    {	
	next = head->next;
	free( head );
	head = next;
    }
    free (_list);
    _list = NULL;
    
}

void list_push_front(  NodeList* _list, Node *_data )
{
    if ( _list->head ) 
    {
	_list->head->prev = _data;
        _data->next = _list->head;
	_list->head = _data;
    }
    else
    {
	_list->head = _data;
	_list->tail = _data;
    }
    _list->size += 1;
}

Node* list_pop_front(  NodeList* _list )
{
    Node* ret = _list->head;
    _list->head = ret->next;
    _list->head->prev = NULL;
    ret->prev = ret->next = NULL;
    _list->size -= 1;
    return ret;
}

void list_push_back( NodeList* _list, Node *_data )
{
    if ( _list->tail )
    {
	_list->tail->next = _data;
	_data->prev = _list->tail;
	_list->tail = _data;
    }
    else
    {
	_list->tail = _data;
	_list->head = _data;
    }
    
    _list->size += 1;
}
 
Node* list_pop_back( NodeList* _list )
{
    Node* ret = _list->tail;
    _list->tail = ret->prev;
    _list->tail->next = NULL;
    ret->next = ret->prev = NULL;
    _list->size -= 1;
    return ret;
}

Node* list_get_pos( NodeList* _list, int pos )
{
    Node* tmp = NULL;
    int _pos = 0;
    for( tmp = _list->head; tmp && _pos != pos-1; tmp = tmp->next, ++_pos );
    return tmp; 
}

/*Вставить _data в _list, в позицию pos */
/*Если не вставит ноду - вернет 1, в случае успеха вернет 0*/
int list_insert( NodeList* _list, int _pos, Node* _data )
{
    Node* tmp = list_get_pos( _list, _pos );
    if ( !tmp ) return 1; 

    Node* tmp_next = tmp->next;
    tmp->next = _data;
    _data->prev = tmp;
    tmp_next->prev = _data;
    _data->next = tmp_next;
    return 0;	
}
/*Удаляет ноду из позиции _pos*/
int list_remove( NodeList* _list, int _pos )
{
    Node* tmp = list_get_pos( _list, _pos );
    if ( !tmp ) return 1; 
    
    Node* tmp_next = tmp->next;
    Node* tmp_prev = tmp->prev;
    tmp_next->prev = tmp_prev;
    tmp_prev->next = tmp_next;
    free( tmp );     
}

void list_print(NodeList* _list)
{
    Node *tmp;
    for( tmp = _list->head; tmp; tmp = tmp->next )
	printf( "%d\n", tmp->num );
}int main ( int argc, char **argv )
{
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


    Node* n9 = node_create();
    Node* n10 = node_create();


    printf ( "size %lu\n", list->size );
    Node *tmp;
    list_print ( list );

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

    
    list_insert( list, 4, n10 );

    list_print ( list );
    printf ( "------------------------------\n" );


    list_remove( list, 5 );

    list_print ( list );
    printf ( "------------------------------\n" );

    list_delete( list );
}
