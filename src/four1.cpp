#include <iostream>
#include <string>
using namespace std;

class Student{};

class StudentList
{
    static int count;
    static const int MAX_NUM = 40; //1 - Ok
    Student stu[5]; //2 - Ok

    public:	
	StudentList() {}
	void Add( string name="", int age );//3 - here
	static int get_max();
};

StudentList::get_max() { return MAX_NUM; } //4 - here

int StudentList::count; //5 - Ok

int main()
{
    return 0;

}