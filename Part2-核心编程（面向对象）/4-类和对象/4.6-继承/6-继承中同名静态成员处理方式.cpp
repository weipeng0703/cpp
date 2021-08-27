/*
问题：继承中同名的静态成员在子类对象上如何进行访问？

静态成员和非静态成员出现同名，处理方式一致

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
    static void func()
    {
        cout << "Base 静态成员函数的调用" << endl;

    }

    static void func(int a)
    {
        cout << "Base 静态成员函数的调用" << endl;

    }

    static int m_A;
};

int Base::m_A = 100;

// 子类
class son : public Base
{
public:
    static void func()
    {
        cout << "son 静态成员函数的调用" << endl;

    }

    static int m_A;
};

int son::m_A = 200;

// 同名静态成员属性
void test1()
{
    son s;
    // 1.通过对象访问
    cout << "通过对象访问静态成员属性：" << endl;
    cout << "son下的m_A=" << s.m_A << endl;          // 自身的
    cout << "Base下的m_A=" << s.Base::m_A << endl;   // 父类的


    // 2.通过类名访问
    cout << "通过类名访问静态成员属性：" << endl;
    cout << "son下的m_A=" << son::m_A << endl;     // 自身的
    // 第一个::代表通过类名方式访问，第二个::代表访问父类作用域下
    cout << "Base下的m_A=" << son::Base::m_A << endl;   // 父类的

}

// 同名静态成员函数的处理方式
void test2()
{
    son s;

    // 1.通过对象访问
    cout << "通过对象访问静态成员函数：" << endl;
    s.func();         // 自身的
    s.Base::func();   // 父类的

    // 2.通过类名访问
    cout << "通过对象访问静态成员函数：" << endl;
    son::func();
    son::Base::func();
    
    // 子类出现和父类同名的静态成员函数，也会隐藏父类中所有同名成员函数
    // 若想访问父类中被隐藏的同名成员，需要加作用域   
    son::Base::func(100);
}

int main()
{
    // test1();
    test2();


    return 0;
}