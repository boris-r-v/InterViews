#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;
class A
{
    public:
	A(){}
	A( A const& a ) { cout << "copy"; }

};

float calc( int, int , float)
{
    return 0.1;
}


float (*port)(int,int,float) = calc;



int main()
{

try {
	A a1;
	A a2 = a1;
	A a3(a2);
	throw a3;
    }
    catch (A a) {  }

    catch (...) {  }


    return 0;
}