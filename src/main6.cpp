#include <iostream>
#include <cstdlib>
#include <exception>
using namespace std;

void my_terminate()
{
    cout << "Внутри my_terminate" << endl;
    abort();
}

void my_unexpected () {
    cout << "Внутри my_unexpected" << endl;
    throw 0;  
}

void my_function () throw (int)
{
    throw 'c';  
}


int main()
{
    set_terminate(my_terminate);

    try
    {
	cout << "Внутри try main " << endl;
	throw 5;    
    }
    catch ( double d ) 
    {
	cout << "catch double " << d << endl;;
    }
    catch ( ... ) 
    {
	cout << "default catch " << endl;;
    }

    set_unexpected (my_unexpected);
    try 
    {
	my_function();
    }
    catch (int) { std::cerr << "caught int\n"; }
    catch (...) { std::cerr << "caught some other exception type\n"; }

    return 0;
}