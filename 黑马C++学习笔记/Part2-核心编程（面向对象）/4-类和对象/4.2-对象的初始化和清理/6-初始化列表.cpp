/*
C++提供了初始化列表语法，用来初始化属性

语法：构造函数()：属性1(值1),属性2（值2）... {}
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:
    // 传统的初始化操作
    // Person(int a, int b, int c) 
    // {
    //     m_A = a;
    //     m_B = b;
    //     m_C = c;
    // }

    // 利用初始化列表初始属性
    Person(int a, int b, int c):m_A(a), m_B(b), m_C(c)
    {

    }

    ~Person() 
    {

    }

    int m_A;
    int m_B;
    int m_C;
};

void test1()
{
    // Person p(10, 20, 30);
    Person p(30, 20, 10);
    cout << "a=" << p.m_A << endl;
    cout << "b=" << p.m_B << endl;
    cout << "c=" << p.m_C << endl;


}

int main()
{
    test1();

    return 0;
}
