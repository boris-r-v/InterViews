#include <iostream>
using namespace std;    

class A
{
    public:
        A() {cout << "+A";}
        ~A() {cout << "-A";}
	static int v;
};


class B
{
    public:
        B() {cout << "+B";}
        ~B() {cout << "-B";}
};

class C
{
    A a;
    B b;
    public:
        C() {cout << "+c";}
        ~C() {cout << "-c";}
};

int A::v = 199;
//int A::v = 199;

int main()
{
    C c;
    return 0;
}