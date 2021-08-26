/*
运算符重载概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的数据类型

加号运算符重载
作用：实现两个自定义数据类型相加的运算

注意：
    1：对于内置的数据类型的表达式的的运算符是不可能改变的
    2：不要滥用运算符重载
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:

    // 1.通过成员函数重载+号   
    Person operator+(Person &p)
    {
        Person temp;
        temp.m_A = this->m_A + p.m_A;
        temp.m_B = this->m_B + p.m_B;

        return temp;

    }
    
    int m_A;
    int m_B;

};

// 2.通过全局函数重载+号
// Person operator+(Person &p1, Person &p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A + p1.m_A;
//     temp.m_B = p2.m_B + p2.m_B;

//     return temp;
// }

// 函数重载的版本
Person operator+(Person &p, int num)
{
    Person temp;
    temp.m_A = p.m_A + num;
    temp.m_B = p.m_B + num;

    return temp;
}
void test1()
{
    Person p1;
    p1.m_A = 10;
    p1.m_B = 10;
    Person p2;
    p2.m_A = 10;
    p2.m_B = 10;

    Person p3 = p1 + p2;

    // 成员重载函数本质调用
    // Person p3 = p1.operator+(p2);

    // 全局重载函数本质调用
    // Person p3 = operator+(p1, p2);

    cout << "p3.m_A=" << p3.m_A << endl;
    cout << "p3.m_B=" << p3.m_B << endl;

    
    // 运算符重载也可以发生函数重载
    Person p4 = p1 + 20;    // Person + int

    cout << "p4.m_A=" << p4.m_A << endl;
    cout << "p4.m_B=" << p4.m_B << endl;
}


int main()
{
    test1();

    return 0;
}