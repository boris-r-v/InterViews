#include <iostream>       // std::cout
#include <unistd.h>

int main ()
{

    for ( int i = 0; i < 300; ++i )
    {
        std::cout << i << std::endl; 
	sleep(1);
    }

  return 0;
}

