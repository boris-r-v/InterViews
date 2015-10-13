#include <iostream>

class B;
class A
{
	friend class B;
	A(){std::cout << "A constructor" << std::endl;}
};

class B : virtual public A
{
    public:
	int x;
	B(){std::cout << "B constructor" << std::endl;}
};

class C : public B
{
    public:
	C(){std::cout << "C constructor" << std::endl;}
};

//B::x = 100;
int main()
{
    C cl_;
    return 0;

}