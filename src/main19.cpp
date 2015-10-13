#include <iostream>
#include <string>
#include <exception>
using namespace std;
class Man
{
	string name_;
    public:
	Man(): name_("Unknown"){}
	Man( string name ): name_(name){}
	~Man () {cout << name_ << " gone" << endl;}
};

//--------------------------
class A
{
    int a;	
    int g(){return 0;}
};
class B
{
    virtual void f14(){}
};


class Bird
{
    public:
	void fly(){cout << "fly" << endl; }
};

class Plane : Bird 
{
    public:
	using Bird::fly;
};
int d = 100;
int &x = d;
Bird ddd;
Bird &bb = ddd;
template < class A, size_t S, Bird& b, int& c, double d, template< class > class T3,  class CH = char >
void ss();


int main(int argc, char *argv[] )
{

    try
    {
	static Man man1("Bill" );
	Man mans[2];
	throw 5;
	Man man4 = string( "Carl" );
    }

    catch (...)
    {
    }	
    cout  << "----------"     << endl;
//-- crash program
/*
    try
    {
	throw 100;
    }
    catch (bool) {cout << "bool" << endl;}
    catch (char) {cout << "char" << endl;}
    catch (exception) {cout << "std::?" << endl;}
*/
//--  12

    cout << sizeof(int) << endl;
    cout << sizeof(A) << endl;

    cout << sizeof(B) << endl;
    cout << (sizeof(A) + sizeof(B) ) << endl;


    int x = 100;
    int y = 200;
    int &n = x;
    n = y;
    cout  << x <<" " << y << " " << n << endl;
    x = 300 - x;
    cout  << x <<" " << y << " " << n << endl;

//------------------

    Plane* superjet100 = new Plane();
    
    superjet100->fly();


//---

	


    return 0;
}


