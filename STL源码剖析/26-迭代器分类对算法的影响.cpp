/*

*/

#include<iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Create A" << endl;

    }

    A(const A& para)
    {
        cout << "拷贝构造 A" << endl;

    }

    ~A()
    {
        cout << "~A" << endl;
    }


};

class B:public A
{
public:
    B(A &a):_a(a)
    {
        cout << "Create B" << endl;
    }

    ~B()
    {
        cout << "~B" << endl;
    }
private:
    A _a;

};



int main()
{
    A a;

    B b(a);

    return 0;
}