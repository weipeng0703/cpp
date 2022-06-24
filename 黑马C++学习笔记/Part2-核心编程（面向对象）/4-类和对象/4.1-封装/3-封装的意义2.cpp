/*
4.1.1 封装的意义
封装是C++面向对象三大特性之一

封装的意义：

1.将属性和行为作为一个整体，表现生活中的事物
2.将属性和行为加以权限控制：
类在设计时，可以把属性和行为放在不同的权限下，加以控制

访问权限有三种：

public 公共权限：       其成员 在类内可以访问，类外可以访问
protected 保护权限：    其成员 在类内可以访问，类外不可以访问，子类可以访问父类的保护内容
private 私有权限        其成员 在类内可以访问，类外不可以访问，子类不可以访问父类的保护内容
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    string m_name;
protected:
    string m_car;
private:
    int m_password;

// 即使成员函数体外部改为public，私有权限和保护权限的成员属性在类外也无法访问
private:
// public:  若改为public，在类外可以访问成员函数    
    void func1()
    {
        m_name = "张三";
        m_car = "拖拉机";
        m_password = 123456;
    } 


};

int main()
{
    Person p1;
    p1.m_name = "李四";
    // p1.m_car = "奔驰";        // 保护权限的内容在类外无法访问
    // p1.m_password = 123456;   // 私有权限的内容在类外无法访问
    // p1.func1();

    return 0;
}