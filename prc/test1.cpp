
class Foo
{
	int *i;
    public:
	Foo( int x ) { i = new int[x];}
	~Foo() {delete i;}
};




class Bar
{
	char *i;
    public:
	Bar( int x ) { i = new char[x];}
	~Bar() {delete i;}
};


int main (int argc, char **argv)
{
    Foo* f = new Foo(100);
    Bar* b = new Bar(200);
    f = b;
    delete f;
    delete b;
}

