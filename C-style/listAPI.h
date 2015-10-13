/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/
/*C-template 
*/
#ifdef T

typedef struct _List //сам список
{
    size_t size;	//кол-во элементов в списке
    T* head;		//голова
    T* tail;		//хвост
} List;

List* list_create( )
{
    List* list = (List*) malloc(sizeof(List) );
    list -> size = 0;
    list -> head = list->tail = NULL;
    return list;
}

void list_delete( List** _list )
{
    T *head = (*_list) -> head;
    T *next = NULL;
    while( head )
    {	
	next = head->next;
	free( head );
	head = next;
    }
    free( *_list );
    (*_list) = NULL;
    
}

void list_push_front(  List* _list, T *_data )
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

T* list_pop_front(  List* _list )
{
    T* ret = _list->head;
    _list->head = ret->next;
    _list->head->prev = NULL;
    ret->prev = ret->next = NULL;
    _list->size -= 1;
    return ret;
}

void list_push_back( List* _list, T *_data )
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

T* list_pop_back( List* _list )
{
    T* ret = _list->tail;
    _list->tail = ret->prev;
    _list->tail->next = NULL;
    ret->next = ret->prev = NULL;
    _list->size -= 1;
    return ret;
}
#endif
