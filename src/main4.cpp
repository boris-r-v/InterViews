#include <iostream>
using namespace std;


int main()
{
    try
    {
	throw 100000000000; //long
	throw 99999999; //int
    }
    catch ( long ) {cout << "long" << endl;}
    catch ( int ) {cout << "int" << endl;}
    catch ( ... ) {cout << "..." << endl;}
}