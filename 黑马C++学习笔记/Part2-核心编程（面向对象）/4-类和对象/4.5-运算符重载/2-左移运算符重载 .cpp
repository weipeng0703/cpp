/*
作用：可以输出自定义数据类型

注：
重载左移运算符配合友元可以实现输出自定义数据类型
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
    // 全局函数做友元
    friend ostream & operator<<(ostream &out, Person &p);
public:
    Person(int a, int b)
    {
        m_A = a;
        m_B = b;
    }

// public:
private:

    // 1.通常不会利用成员函数重载左移运算符，因为无法实现cout在左侧

    int m_A;
    int m_B;

};

// 2.只能利用全局函数重载左移运算符
// 引用的本质就是起一个别名，所以这儿的out可以换为任意合法的东西
ostream & operator<<(ostream &out, Person &p)   // 本质是operator<< (cout , p)
{
    out << "m_A=" << p.m_A << "\nm_B=" << p.m_B;

    return out; 
}

void test1()
{
    Person p(10, 10);

    cout << p << "\nhello world!" << endl;
    // cout << "p.m_A=" << p.m_A << endl;
    // cout << "p.m_B=" << p.m_B << endl;

}


int main()
{
    test1();

    return 0;
}