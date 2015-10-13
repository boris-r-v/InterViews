#include <iostream>
#include <string>
using namespace std;
//int StudentList::count; //5 - Ok
//    const char *p2c = &a1; //Указатель на контанту
//    char * const cp = &a1; //Константный указатель


class X
{
    public:
	X(int){};
};

class Y
{
    public:
	Y(X){};
};

class Z
{
    public:
	Z(){};
	Z(X){};
	operator Y(){};
    
};
void f(X){};
void g(Y){};
void h(Z){};

int main()
{

    f( 10 );
    g( Z () );
    g( Z( 10 ) );
    h( X( 10 ) );
    //h( 10 );  - bug here

}