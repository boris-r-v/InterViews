#include <iostream>
using namespace std;


class FO
{
    double x,y,z;
    double vx,vy,vz;
};

class D: public FO //FO
{
    double BurnerPower;
};

class A: public FO //FO
{
    double EnginePower;
};


int main(int argc, char *argv[] )
{

    A a_;
    D d_;
    FO *fpo[2];
    
    fpo[0] = &a_;
    fpo[1] = &d_;
    
}

