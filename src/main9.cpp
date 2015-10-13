#include <iostream>
#include <cstdlib>
#include <exception>

#define max(a,b) ((a) < (b) ? (b) : (a))

using namespace std;

int main()
{
    int a = 10;
    int b = 20;
    int c =  max( a+=5, b );
    cout << c << endl;
    a=10;
    int d = ( a+=5 < b ? b : a );
    cout << d << endl;

    a=10;
    cout << (a+=5) << endl;

    cout << "---------------------" << endl;

    bool l1 = 0x0f, l2 = 0xfa;
    cout << hex << (l1 & l2) << endl;    



    return 0;
}