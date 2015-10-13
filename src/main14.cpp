#include <iostream>
#include <list>
#include <algorithm> 

using namespace std;


class Student
{

    public:	
	string family_;
	Student( string _s ): family_( _s ) {}
};

class Finder
{
    public:
	string family_;
    
    bool operator()( Student const& _s)
    {
	return family_ == _s.family_;
    };

};

int main()
{
    list <Student> _l;
    _l.push_back( Student("1" ) );

    _l.push_back( Student("2" ) );
    _l.push_back( Student("3" ) );
    _l.push_back( Student("4" ) );

    Finder _f; 
    _f.family_ = "2";
    std::list<Student>::iterator f = std::find_if( _l.begin(), _l.end(), _f );
    cout << f->family_ << endl;
    return 0;
}
