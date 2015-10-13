#include <iostream>
#include <string>
using namespace std;
//int StudentList::count; //5 - Ok

template <class R, class P>
R implicit_cast( const P& p ) {return p;}

template <class R, class P>
R explicit_cast( const P& p ) {return p;}


template <class T>
class X
{
	typename T::id i;
    public:
	void f() {i.g();}
};

class Y
{
    public:
	class id
	{
	    public:
		void g(){}    		
	};
    
};


int main()
{
    int i=4;
    float x = implicit_cast<float>(i); //1
    int j = implicit_cast<int>(x); //2
    bool b = implicit_cast<bool, int>(i); //3

    int k = explicit_cast<int>(x); //4
    double d = explicit_cast<double, double>(5.7); //5

    
    char a1, b1;
    const char *p2c = &a1; //Указатель на контанту

    char * const cp = &a1; //Константный указатель

    p2c = &b1;
    *p2c = 'Z';

    cp = &b1;
    *cp = 'Z';


    return 0;
}