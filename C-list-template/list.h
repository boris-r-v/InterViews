/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/
#ifndef TEMPLATES_H_
#define TEMPLATES_H_

#define CAT(X,Y) X##_##Y
#define TEMPLATE(X,Y) CAT(X,Y)

#endif
#ifdef E	

#define T E
#define LIST_NODE_GET_TYPE  TEMPLATE(T,ListNode)
#define LIST_NODE_CREATE  TEMPLATE(T,ListNodeCreate)
#define LIST_NODE_DATA  TEMPLATE(T,ListNodeData)
#define LIST_GET_TYPE  TEMPLATE(T,List)
#define LIST_CREATE  TEMPLATE(T,list_create)
#define LIST_DELETE  TEMPLATE(T,list_delete)
#define LIST_PUSH_FRONT  TEMPLATE(T,list_push_front)
#define LIST_POP_FRONT  TEMPLATE(T,list_pop_front)
#define LIST_PUSH_BACK TEMPLATE(T,list_push_back)
#define LIST_POP_BACK TEMPLATE(T,list_pop_back)
#define LIST_GET_POS TEMPLATE(T,list_get_pos)
#define LIST_INSERT TEMPLATE(T,list_insert)
#define LIST_REMOVE TEMPLATE(T,list_remove)
#define LIST_BEGIN_NODE TEMPLATE(T,list_begin_node)
#define LIST_NEXT_NODE TEMPLATE(T,list_next_node)

typedef struct TEMPLATE(T,_ListNode)
{
    T* data;				//полезные данные
    struct TEMPLATE(T,_ListNode) *prev;	//указатель на предыдущего
    struct TEMPLATE(T,_ListNode) *next;	//указатель на последующего

}LIST_NODE_GET_TYPE;

LIST_NODE_GET_TYPE* LIST_NODE_CREATE( T* _data )
{
    LIST_NODE_GET_TYPE* ret = (LIST_NODE_GET_TYPE*) malloc(sizeof(LIST_NODE_GET_TYPE) );
    ret->data = _data;
    ret->prev = ret->next = NULL;
}

T* LIST_NODE_DATA( LIST_NODE_GET_TYPE* _node )
{
    return _node -> data;
}

typedef struct TEMPLATE(T,_List) //сам список
{
    size_t size;			//кол-во элементов в списке
    LIST_NODE_GET_TYPE* head;		//голова
    LIST_NODE_GET_TYPE* tail;		//хвост
} LIST_GET_TYPE;

LIST_GET_TYPE* LIST_CREATE( )
{
    LIST_GET_TYPE* list = (LIST_GET_TYPE*) malloc(sizeof(LIST_GET_TYPE) );
    list -> size = 0;
    list -> head = list->tail = NULL;
    return list;
}

void LIST_DELETE( LIST_GET_TYPE* _list )
{
    LIST_NODE_GET_TYPE *head = _list -> head;
    LIST_NODE_GET_TYPE *next = NULL;
    while( head )
    {	
	next = head->next;
	free( head );
	head = next;
    }
    free( _list );
    _list = NULL;
}

void LIST_PUSH_FRONT(  LIST_GET_TYPE *_list, T *_data )
{

    LIST_NODE_GET_TYPE* node = LIST_NODE_CREATE(_data );
    
    if ( _list->head ) 
    {
	_list->head->prev = node;
        node->next = _list->head;
	_list->head = node;
    }
    else
    {
	_list->head = node;
	_list->tail = node;
    }
    _list->size += 1;
}

T* LIST_POP_FRONT(  LIST_GET_TYPE *_list )
{
    LIST_NODE_GET_TYPE* ret = _list->head;
    _list->head = ret->next;
    _list->head->prev = NULL;
    _list->size -= 1;
    T* data = ret->data;
    free( ret );
    return data;
}

void LIST_PUSH_BACK( LIST_GET_TYPE* _list, T *_data )
{
    LIST_NODE_GET_TYPE* node = LIST_NODE_CREATE(_data );
    if ( _list->tail )
    {
	_list->tail->next = node;
	node->prev = _list->tail;
	_list->tail = node;
    }
    else
    {
	_list->tail = node;
	_list->head = node;
    }
    
    _list->size += 1;
}

T* LIST_POP_BACK( LIST_GET_TYPE* _list )
{
    LIST_NODE_GET_TYPE* ret = _list->tail;
    _list->tail = ret->prev;
    _list->tail->next = NULL;
    ret->next = ret->prev = NULL;
    _list->size -= 1;
    T* data = ret->data;
    free(ret);
    return data;
}

LIST_NODE_GET_TYPE* LIST_GET_POS( LIST_GET_TYPE* _list, int pos )
{
    LIST_NODE_GET_TYPE* tmp = NULL;
    int _pos = 0;
    for( tmp = _list->head; tmp && _pos != pos-1; tmp = tmp->next, ++_pos );
    return tmp; 
}

/*Вставить _data в _list, в позицию pos */
/*Если не вставит ноду - вернет 1, в случае успеха вернет 0*/
int LIST_INSERT( LIST_GET_TYPE* _list, int _pos, T* _data )
{
    LIST_NODE_GET_TYPE* tmp = LIST_GET_POS( _list, _pos-1 );
    if ( !tmp ) return 1; 

    LIST_NODE_GET_TYPE* node = LIST_NODE_CREATE(_data );
    LIST_NODE_GET_TYPE* tmp_next = tmp->next;
    tmp->next = node;
    node->prev = tmp;
    tmp_next->prev = node;
    node->next = tmp_next;
    return 0;	
}
/*Удаляет ноду из позиции _pos*/
T* LIST_REMOVE( LIST_GET_TYPE* _list, int _pos )
{
    LIST_NODE_GET_TYPE* tmp = LIST_GET_POS( _list, _pos );
    if ( !tmp ) return NULL; 
    
    LIST_NODE_GET_TYPE* tmp_next = tmp->next;
    LIST_NODE_GET_TYPE* tmp_prev = tmp->prev;
    tmp_next->prev = tmp_prev;
    tmp_prev->next = tmp_next;
    T* data = tmp->data;
    free(tmp);
    return data;
}

LIST_NODE_GET_TYPE* LIST_BEGIN_NODE(LIST_GET_TYPE* _list)
{
    return _list->head;
}

LIST_NODE_GET_TYPE* LIST_NEXT_NODE( LIST_NODE_GET_TYPE* _node)
{
    return _node->next;
}



#endif