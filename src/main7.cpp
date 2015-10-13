#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

class A
{
    public:
	~A() {cout << "A";}
};


class B
{
    public:
	~B() {cout << "B";}
};

class C
{
    public:
	~C() {cout << "C";}
};


class F
{
    public:
	~F() {cout << "F";}
};

class Pointer
{
    public:
	~Pointer() {cout << "Pointer";}
};

void my_function()
{
    F f;
    Pointer *p = new Pointer();
}

int main()
{
    try 
    {
	A a;
	my_function();
	B b[2];
	cout << endl;
	throw 3;
    }
    catch (int) { }


    return 0;
}