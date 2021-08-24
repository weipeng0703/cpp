/*
在C++中，类内的成员变量和成员函数分开存储

只有非静态成员变量才属于类的对象上
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:
    int m_A;   // 非静态成员变量   属于类的对象

    static int m_B;    // 静态成员变量   不属于类的对象上

    void func(/* args */) {}   // 非静态成员函数   不属于类的对象上
    static void func1(/* args */) {}   // 静态成员函数   不属于类的对象上
};

int Person::m_B = 100; 
void test1()
{
    Person p;

    // 空对象占用的内存空间为1
    // C++编译器会给每个空对象分配一个自己空间，是为了区分空对象占内存的位置
    // 每个空对象都应该有一个独一无二的内存地址
    cout << "空对象占用的内存空间为" << sizeof(p) << endl;

}

void test2()
{
    Person p;

    cout << "一个非静态成员变量占用的内存空间为" << sizeof(p) << endl;

}

int main()
{
    // test1();
    test2();

    return 0;
}