/*
子类继承父类后，当创建子类对象，也会调用父类的构造函数

问题：父类和子类的构造和析构顺序是谁先谁后？

总结：继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反
*/
#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base构造函数" << endl;
    }

    ~Base()
    {
        cout << "Base析构函数" << endl;
    }
};

class son : public Base
{
public:
    son()
    {
        cout << "Son构造函数" << endl;
    }

    ~son()
    {
        cout << "Son析构函数" << endl;
    }
};

void test1()
{
    // Base b;

    son s;

}

int main()
{
    test1();
    // test2();
    // test3();

    return 0;
}