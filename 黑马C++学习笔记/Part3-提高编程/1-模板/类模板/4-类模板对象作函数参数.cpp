/*
学习目标：

    类模板实例化出的对象，向函数传参的方式

一共有三种传入方式：

    1.指定传入的类型 — 直接显示对象的数据类型
    2.参数模板化 — 将对象中的参数变为模板进行传递
    3.整个类模板化 — 将这个对象类型 模板化进行传递
*/

#include<string>
#include<iostream>
using namespace std;


template<class T1, class T2>
class Person
{
public:

    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }

    void ShowPerson()
    {
        cout << "姓名为：" << this->m_Name << " 年龄为：" << this->m_Age << endl;
    }

    T1 m_Name;
    T2 m_Age;


};


// 1.指定传入类型 ：开发中最常用
void PrintPerson1(Person<string, int>&p)
{
    p.ShowPerson();

}

void test1()
{
    Person<string, int>p1("孙悟空", 200);
    PrintPerson1(p1);
}

// 2.参数模板化
template<class T1,class T2>
void PrintPerson2(Person<T1, T2>&p)
{
    p.ShowPerson();
    cout << "T1的类型为：" << typeid(T1).name() << endl;
    cout << "T2的类型为：" << typeid(T2).name() << endl;

}

void test2()
{
    Person<string, int>p2("猪八戒", 300);
    PrintPerson2(p2);
}

// 3.整个类模板化
template<class T>
void PrintPerson3(T &p)
{
    p.ShowPerson();
    cout << "T的类型为：" << typeid(T).name() << endl;

}

void test3()
{
    Person<string, int>p3("唐僧", 30);
    PrintPerson3(p3);
}


int main()
{
    test1();
    test2();
    test3();

    return 0;
}