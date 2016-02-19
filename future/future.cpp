// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
class A
{
    public:
	bool is_prime (int x) 
	{
	    std::cout << "is_prime_ method invoke " << x << std::endl;
	    for (int i=2; i<x; ++i) if (x%i==0) return false;
	    return true;
	}
	std::future<bool> fut;
	void calc()
	{
	     // call function asynchronously:
	    std::cout << ":: " << fut.valid() << std::endl;
	    fut = std::async (std::launch::async, [ this ]( int x ){ return this->is_prime( x ); }, 444444443); 

	    std::cout << ":: " << fut.valid() << std::endl;

	    std::chrono::milliseconds span (100);
	    while ( fut.wait_for(span)==std::future_status::timeout) 
	    {
		    std::cout << '.' << std::flush;
	    }
	    std::cout << "get" << std::endl;
	    std::cout << ":: " << fut.valid() << std::endl;

	      bool x = fut.get();     // retrieve return value

	    std::cout << ":: " << fut.valid() << std::endl;

	    std::cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";

	}

};

int main ()
{

    A a;
    a.calc();

    a.calc();

  return 0;
}

