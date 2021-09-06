/*
学习目标：能够掌握类模板中的成员函数类外实现
*/

#include<string>
#include<iostream>
using namespace std;

template<class T1, class T2>
class Person
{
public:
    // 类内只需要进行声明
    Person(T1 name, T2 age);

    void ShowPerson();


    T1 m_Name;
    T2 m_Age;

};

// 构造函数类外实现
template<class T1, class T2>
// Person::Person(T1 name, T2 age)  // 普通成员函数的类外实现
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->m_Name = name;
    this->m_Age = age;

}
// 成员函数的类外实现
template<class T1, class T2>
// Person::Person(T1 name, T2 age)  // 普通成员函数的类外实现
void Person<T1, T2>::ShowPerson()
{
    cout << "姓名：" << this->m_Name << " 年龄：" << this->m_Age << endl;
}


void test1()
{
    Person<string, int>p("Tom", 20);
    p.ShowPerson();
}

int main()
{
    test1();



    return 0;
}