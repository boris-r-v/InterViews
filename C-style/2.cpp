#include <iostream>


using namespace std;

extern int g1;
extern const int g2;
extern const int g5;
extern int g3;
extern volatile int g4;

int main ()
{

    cout << g1 << endl;
    cout << g2 << endl;
    cout << g3 << endl;
    cout << g4 << endl;
    cout << g5 << endl;

}