#include <iostream>
using namespace std;

namespace X
{
    int x = 5;
    namespace Y
    {
	int x = 2;
	void f()
	{
	    for ( int i = 1; i < 10; ++i ) 
	    {
		int x = 10;
		X::x += Y::x * x;
	cout << "X::x=" << X::x << " Y::x=" << Y::x << " x=" << x << endl;
	    }
	}
    }
}

int main(int argc, char *argv[] )
{

    X::Y::f();
    cout << X::x << endl;

    
}
