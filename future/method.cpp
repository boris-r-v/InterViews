// future example
#include <iostream>       // std::cout
#include <future>         // std::async, std::future
#include <chrono>         // std::chrono::milliseconds
#include <functional>  	  // std::binf, std::function

// a non-optimized way of checking for prime numbers:
/*template( class RetVal, class cb, class Fn, class ... Args )
class cb_wrapper
{
	RetVal ret_val_;
    public:
	void invoke		
};
*/

template< class RetVal, class cb, class Fn, class ... Args >
void invoke (RetVal b, cb&& callback, Fn&& fn, Args&& ... args )
{

    std::future<RetVal> fut  = std::async( std::launch::async, fn, args... ); 
    fut.wait();
    
    callback( fut.get() );
        
};

template < class RetVal, class cb, class Fn, class ... Args >
void wrap (RetVal b, cb&& callback, Fn&& fn, Args&& ... args)
{
    std::future <void> ff = std::async( std::launch::async, fn, args... );
}

class A
{
    public:
	void done( bool x )
	{
	    std::cout << "\n444444443 " << (x?"is":"is not") << " prime.\n";
	}
	bool is_prime (int x) 
	{
	    std::cout << "is_prime_ method invoke " << x << std::endl;
	    for (int i=2; i<x; ++i) if (x%i==0) return false;
	    return true;
	}

	void calc()
	{
	    using namespace std::placeholders;
	    bool rv;
	    std::thread ff (invoke, rv, std::bind( &A::done, this, _1 ), [this](int x){return this->is_prime(x);}, 444444443 );
	    ff.detach();
	}

};

int main ()
{

    A a;
    a.calc();
    std::chrono::milliseconds span (100);
    for ( int i = 0; i < 30; ++i ) 
    {
	std::cout << '.' << std::flush;
	std::this_thread::sleep_for( span );
    }


  return 0;
}

