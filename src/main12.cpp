#include <iostream>
#include <typeinfo>

using namespace std;

class Vechile
{
    public:
	void run(){cout << "run";}
};

class Car: public Vechile
{
	
};

class Foo
{
    public:
	Foo(int i):int_(i){ cout << int_;}
	Foo(Foo const& f):int_(f.int_){ cout << int_;}
    private:
	int int_;
};


int main()
{
    Car* car = new Car();
    car->run();


    Foo f1(111);
    Foo f2(f1);

    return 0;
}