#include <iostream>
#include <typeinfo>
using namespace std;

struct Type{};
class Base{};
int main()
{
    Type tpn;
    const Type tp;
    const Type* const ptp = &tp;
    const Type* ptp1 = &tpn;
    Type* const ptp2 = &tpn;
    cout << boolalpha << typeid(ptp).name() << endl;
    cout << boolalpha << typeid(ptp1).name() << endl;
    cout << boolalpha << typeid(ptp2).name() << endl;
    cout << boolalpha << typeid(tp).name() << endl;
    cout << boolalpha << typeid(tpn).name() << endl;

    Base bs;
    
    cout << boolalpha << typeid(bs).name() << endl;

    //cout << typeid(ptp).name() << endl;

    return 0;
}