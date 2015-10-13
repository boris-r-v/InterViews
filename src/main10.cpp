#include <iostream>
#include <typeinfo>

using namespace std;

class A
{
    public:
	A() {cout << "+A";}
	~A() {cout << "-A";}
};

class B: public A
{
    public:
	B() {cout << "+B";}
	~B() {cout << "-B";}
};

class C: private B
{
    public:
	C() {cout << "+C";}
	~C() {cout << "-C";}
};

class D: public A
{
    public:
	D() {cout << "+D";}
	~D() {cout << "-D";}
};



void func ( int i )
{
    static int c = 0;
    ++c;
    cout << c;
}

int main()
{

    delete [] new A[4];
    cout << endl;
    for (int i=0; i<9; ++i) func( 0 );
    cout << endl;
    C cl;
    cout << endl;

    D* d_ = new D();
    B* b_ = new B();

    cout << endl << (typeid(d_) == typeid(b_)) << endl;
    return 0;
}