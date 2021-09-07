#pragma once
#include<iostream>
#include<string>
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

template<class T1, class T2>
// Person::Person(T1 name, T2 age)  // 普通成员函数的类外实现
Person<T1, T2>::Person(T1 name, T2 age)   // 类模板成员函数的的类外实现
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

