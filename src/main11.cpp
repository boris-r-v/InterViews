#include <iostream>
#include <typeinfo>

using namespace std;

class Base
{
    public:
	Base() {throw 6;}
};

class Derived: public Base
{
    public:
	Derived()
	    try: Base()
	    {
	    }
	    catch ( ... )
	    {
		cout << "1";
	    }
	
};

struct node {double x,y,z,w;};

int main()
{
    try
    {
	Derived der;
    }
    catch(int)
    {
	cout << "2";
    }


    cout <<endl;

    node cube[] = 
    {
	{1,1,1,1},{1,1,1,1},
	{1,1,1,1},{1,1,1,1},
	{1,1,1,1},{1,1,1,1},
	{1,1,1,1},{1,1,1,1}
    };
    return 0;
}