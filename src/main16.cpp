#include <iostream>
#include <memory> 
#include <fstream> 

using namespace std;


void use ( auto_ptr<int> ptr )
{
    (*ptr)++;
}

template <class T>
class Test
{
	static T mqa;
	T md;
    public:
	virtual void set( T i){md = i;};
	static T get(){ return mqa; }
};
/* //error: templates may not be ‘virtual’
class f
{
    public:
	template <class T> virtual T get();    //error: templates may not be ‘virtual’
};
*/

class B
{
    ~B() throw(){}
};

int (*ptr[4])();
int get(){}

int main(int argc, char *argv[] )
{
    auto_ptr<int> p ( new int[10] );

    //use ( p );
    cout << *p << endl;

    Test <int > st;
    
    cout << (double)23456789000 << endl; // 2.34568e+10

    ptr[0] = get;
    ptr[1] = get;
    ptr[2] = get;
    ptr[3] = get;


    cout << endl;

    ifstream ifs;
    ifs.open( "./c.txt" );

    char s;

    while ( ifs.good() ) 
    {
        ifs >> s;
	cout << s;
    }

    ifs.close();

    return 0;

}
