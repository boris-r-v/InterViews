#include <iostream>
using namespace std;

struct Strange
{
   Strange()
   {
      cout << "Hello" << endl;
   }

   ~Strange()
   {
      cout << "Bye" << endl;
   }

} tagStrange;

int main()
{
   return 0;
}

