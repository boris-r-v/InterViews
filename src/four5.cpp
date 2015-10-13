#include <iostream>
#include <string>
using namespace std;
//int StudentList::count; //5 - Ok
//    const char *p2c = &a1; //Указатель на контанту
//    char * const cp = &a1; //Константный указатель

class A
{
    public:
	A(){ cout << "A";}
	~A(){ cout << "~A"; throw 1;}
/*	void* operator[](size_t size )
	{
	    return malloc(size);
	}
	void operator delete[](void* mem)
	{
	    free(mem);
	}
*/
};

class Person { virtual void f(){} };
class Student: public Person{};

int main()
{
    Person pr;
    const Person* p = &pr;
    Student * st = dynamic_cast<Student*>( const_cast<Person*>(p) );
    

    try
    {
	A* p = new A[2];
	delete [] p;
    }
    catch (...)
    {
	cout << "ok";
    }

    return 0;
}