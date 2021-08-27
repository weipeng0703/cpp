/*
问题：当子类与父类出现同名的成员，如何通过子类对象，访问到子类或父类中同名的数据呢？

访问子类同名成员 直接访问即可
访问父类同名成员 需要加作用域
*/
#include<iostream>
#include<string>
using namespace std;

// 父类
class Base
{
public:

    Base()
    {
        m_A = 100;
    }

    void func()
    {
        cout << "Base - func()的调用" << endl;
    }

    void func(int a)    // 重载
    {
        cout << "Base - 重载func()的调用" << endl;
    }


    int m_A;
};

// 子类
class son : public Base
{
public:

    son()
    {
        m_A = 200;
    }

    void func()
    {
        cout << "son - func()的调用" << endl;
    }


    int m_A;
};

// 同名成员属性的处理方式
void test1()
{
    son s;

    cout << "son下的m_A=" << s.m_A << endl;   // 自身的
    cout << "Base下的m_A=" << s.Base::m_A << endl;   // 父类的

}

// 同名成员函数的处理方式
void test2()
{
    son s;

    s.func();         // 自身的
    s.Base::func();   // 父类的

    // 如果子类中出现和父类同名的成员函数，子类的同名成员会隐藏掉父类中所有同名成员函数
    // 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    s.Base::func(100);

}

int main()
{
    // test1();
    test2();


    return 0;
}