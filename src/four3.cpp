#include <iostream>
#include <string>
using namespace std;
//int StudentList::count; //5 - Ok
//    const char *p2c = &a1; //Указатель на контанту
//    char * const cp = &a1; //Константный указатель


bool check()
{
    static int cn = 0;
    ++cn;
    return cn % 2;
}

enum  {cs9600cps, cs14400cps};

int main()
{
    bool b = false;
    for ( int i = 0; i<3 && !b; ++i )
    {	
	b = check();
	if ( !b )
	    cout << "нечет" << std::endl;
	else
	    cout << "чет" << std::endl;
    }
    return 0;
}