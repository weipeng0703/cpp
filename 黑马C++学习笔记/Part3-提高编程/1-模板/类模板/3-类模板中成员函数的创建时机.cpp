/*
类模板中成员函数和普通类中成员函数创建时机是有区别的：

    普通类中的成员函数一开始就可以创建
    类模板中的成员函数在调用时才创建
*/

#include<string>
#include<iostream>
using namespace std;


class Person1
{
public:
    void ShowPerson1()
    {
        cout << "Person1 Show" << endl;
    }


};

class Person2
{
public:
    void ShowPerson2()
    {
        cout << "Person2 Show" << endl;
    }


};

template<class T>
class MyClass
{
public:
    T obj;

    // 类模板中的成员函数
    void func1()
    {
        obj.ShowPerson1();
    }

    void func2()
    {
        obj.ShowPerson2();
    }

};



void test1()
{
    MyClass<Person1>m;
    m.func1();
    // m.func2();


    MyClass<Person2>m1;
    // m.func1();
    m1.func2();

}


int main()
{
    test1();
    // test2();
    
    return 0;
}