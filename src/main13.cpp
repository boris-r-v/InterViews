#include <iostream>
using namespace std;

template < class T = int, int N = 100 > //1
class Stack
{
	T data[N];
	size_t count;
    public:
	void push ( const T& t) {}
};

int main()
{
    Stack<> myStack; //2
    Stack <float, 5> fltStack1; 	
    Stack <float, 6> fltStack2; 	
    Stack <int, 100> intStack; 	
    intStack = myStack; //3
    //fltStack1 = fltStack2; //4 - ТУТ т.к. параметры шаблонов разные 5 и 6

    return 0;
}