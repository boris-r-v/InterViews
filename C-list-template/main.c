/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _Element	//Структура хранимая в списке
{
    int num; 		//некоторые полезные данные
} Element;

Element* element_create( int d )
{
    static int i = 0;
    Element* ret = (Element*) malloc(sizeof(Element) );
    ret -> num = d ? d : ++i;
    return ret;
}
#define E Element
#include "list.h"

void e_list_print( LIST_GET_TYPE *elist )
{
    printf("-------------------------\n");
    LIST_NODE_GET_TYPE* n = LIST_BEGIN_NODE( elist );
    for (; n; n = LIST_NEXT_NODE( n ) )
    {
	Element* d = LIST_NODE_DATA ( n );
	printf ( "%d\n", d->num ); 
    }
    printf("-------------------------\n");
}

void work_element()
{
    LIST_GET_TYPE *elist = LIST_CREATE();
    Element* e1 = element_create(0);

    Element* e2 = element_create(0);
    Element* e3 = element_create(0);
    Element* e4 = element_create(0);
    
    LIST_PUSH_BACK( elist, e1 );
    LIST_PUSH_BACK( elist, e2 );
    LIST_PUSH_FRONT( elist, e3 );
    LIST_PUSH_FRONT( elist, e4 );

    e_list_print( elist );

    Element* e500 = element_create(500);
    LIST_INSERT( elist, 2, e500 );
    e_list_print( elist );

    LIST_REMOVE( elist, 3 );
    e_list_print( elist );

    LIST_POP_BACK( elist  );
    LIST_POP_FRONT( elist  );
    e_list_print( elist );

    LIST_DELETE ( elist );

}
#undef E

typedef struct _Node	//Структура хранимая в списке
{
    int num; 		//некоторые полезные данные
} Node;
Node* node_create( int d )
{
    static int i = 0;
    Node* ret = (Node*) malloc(sizeof(Node) );
    ret -> num = d ? d : ++i;
    return ret;
}
#define E Node
#include "list.h"

void n_list_print( LIST_GET_TYPE *nlist )
{
    printf("-------------------------\n");
    LIST_NODE_GET_TYPE* n = LIST_BEGIN_NODE( nlist );
    for (; n; n = LIST_NEXT_NODE( n ) )
    {
	Node* d = LIST_NODE_DATA ( n );
	printf ( "%d\n", d->num ); 
    }
    printf("-------------------------\n");
}
void work_node()
{


    LIST_GET_TYPE *nlist = LIST_CREATE();
    Node* e1 = node_create(0);

    Node* e2 = node_create(0);
    Node* e3 = node_create(0);
    Node* e4 = node_create(0);
    
    LIST_PUSH_BACK( nlist, e1 );
    LIST_PUSH_BACK( nlist, e2 );
    LIST_PUSH_FRONT( nlist, e3 );
    LIST_PUSH_FRONT( nlist, e4 );

    n_list_print( nlist );

    Node* e500 = node_create(500);
    LIST_INSERT( nlist, 30, e500 );
    n_list_print( nlist );

    LIST_REMOVE( nlist, 3 );
    n_list_print( nlist );

    LIST_POP_BACK( nlist  );
    LIST_POP_FRONT( nlist  );
    n_list_print( nlist );
    
    LIST_DELETE ( nlist );

}
#undef E

int main ( int argc, char **argv )
{
    work_element();    
    printf("+++++++++++++++++++++++++++++++++++++\n");
    work_node();    

}
