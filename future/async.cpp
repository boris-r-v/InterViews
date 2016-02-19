// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds

// a non-optimized way of checking for prime numbers:
class A
{
    public:

	void work_prime( int x )
	{
	    std::cout << "\n444444443 " << (is_prime(x) ? "is":"is not") << " prime.\n";
	}
	bool is_prime (int x) 
	{
	    std::cout << "is_prime_ method invoke " << x << std::endl;
	    for (int i=2; i<x; ++i) if (x%i==0) return false;
	    return true;
	}
	//std::future<void> fut;
	void calc()
	{
	     // call function asynchronously:
	    std::future<void> fut = std::async ( std::launch::async, [ this ]( int x ){ return this->work_prime( x ); }, 444444443); 

	    std::chrono::milliseconds span (100);
	    for ( int i = 0; i < 30; ++i ) 
	    {
		std::cout << '.' << std::flush;
		std::this_thread::sleep_for( span );
	    }
	}

};

int main ()
{

    std::cout << 7210 % 3600 << std::endl; 
    for ( int i = 3500; i < 3600*24; i += 2000 )
    {
	long l = i/3600;
        std::cout << i << " % 3600 = " << 100 * l << std::endl; 
    }
    A a;
    a.calc();

  return 0;
}

