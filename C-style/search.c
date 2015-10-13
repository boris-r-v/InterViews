/*
copyright Boris Rozhkin borisrozhkin@gmail.com
*/

#include <stdio.h>
#define MAX_LEN 10
/*( массив, размер_массивы, элемент_позицию_которого_надо_найти, указатель_на_переменную_куда_записать_найденную_позицию )*/
#define FIND( _arr, _size, _data, _ret )  ({int _i; for ( (_i) = 0; _i < (_size) && (_data) != (_arr[_i]); (++_i), *(_ret) = (_i) ); if ( (_i) == (_size) ) *(_ret) = -1;} )

int find_int(int* arr, int size, int data, int* ret )
{
    int i; for ( i = 0; i < size && data != arr[i]; ++i, *ret = i ); if ( i == size ) *ret = -1;
}

int find_float(char* arr, int size, char data, int* ret )
{
    int i; for ( i = 0; i < size && data != arr[i]; ++i, *ret = i ); if ( i == size ) *ret = -1;
}

int main ( int argc, char **argv )
{
    /*для int*/
    int arr[MAX_LEN];
    int i;
    for (i = 0; i < MAX_LEN; ++i )
	arr[i] = i;

    int data = 4;
    int pos;
    find_int(arr, MAX_LEN, data, &pos );
    printf ( "find_method %d pos %d\n", data+1, pos ); 

    pos = -1;
    FIND( arr, MAX_LEN, data, &pos );
    printf ( "find_macros %d pos %d\n", data+1, pos ); 

    /*для char*/
    char arrf[MAX_LEN];
    for (i = 0; i < MAX_LEN; ++i )
	arrf[i] = i;

    pos = -1;	
    char dataf = 40;
    find_float(arrf, MAX_LEN, dataf, &pos );
    printf ( "find_method %d pos %d\n", dataf, pos ); 

    pos = -1;	
    FIND( arrf, MAX_LEN, dataf, &pos );
    printf ( "find_macros %d pos %d\n", dataf, pos ); 
}

