#include <iostream>

using namespace std;

class A
{
    public:
	~A() {cout << "A";}
};


class B
{
	mutable int n;
    public:
	static int l;
	B() {n=l;  ++l;}
	~B() {cout << "B" <<n;}
	static void free() { l = -100; };
	void freez() const {n=-199;}
    
};

class C
{
    public:
	~C() {cout << "C";}
};

int B::l = 199;

int main()
{

    cout << B::l << endl;

    C c;
    try
    {
	A a;
	B b[3];
	throw 5;    
    }
    catch ( ... ) {cout << "catch";}
    cout << endl;

    B b;
    return 0;
}