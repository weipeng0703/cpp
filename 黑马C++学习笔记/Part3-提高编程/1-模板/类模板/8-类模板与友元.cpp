/*
学习目标：
掌握类模板配合友元函数的类内和类外实现
    全局函数类内实现 - 直接在类内声明友元即可
    全局函数类外实现 - 需要提前让编译器知道全局函数的存在

总结：建议全局函数做类内实现，用法简单，而且编译器可以直接识别；类外实现过于复杂
*/

#include<string>
#include<iostream>
using namespace std;

// 让编译器提前知道类的存在
template<class T1, class T2>
class Person;
// 全局函数，类外实现
template<class T1, class T2>
void PrintPerson2(Person<T1, T2> p)
{
    cout << "类外实现：姓名为：" << p.m_Name << " 年龄为：" << p.m_Age << endl;

}

// 通过全局函数打印Person的信息
template<class T1, class T2>
class Person
{
    // 全局函数，类内实现
    friend void PrintPerson(Person<T1, T2> p)
    {
        cout << "类内实现：姓名为：" << p.m_Name << " 年龄为：" << p.m_Age << endl;

    }

    // 全局函数，类外实现，只需在类内写函数声明
    // 如果全局函数是类外实现，得让编译器提前知道这个函数的存在
    friend void PrintPerson2<>(Person<T1, T2> p);  // 加空模板参数列表

public:

    Person(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }


private:
    T1 m_Name;
    T2 m_Age;

};


void test1()
{
    Person<string, int>p("Tom", 20);
    PrintPerson(p);
}


void test2()
{
    Person<string, int>p2("Jerry", 10);
    PrintPerson2(p2);
}

int main()
{
    test1();
    test2();

    return 0;
}