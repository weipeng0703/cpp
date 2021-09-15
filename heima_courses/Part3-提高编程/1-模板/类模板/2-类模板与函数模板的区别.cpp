/*
类模板与函数模板区别主要有两点：
    类模板没有自动类型推导的使用方式
    类模板在模板参数列表中可以有默认参数
*/

#include<string>
#include<iostream>
using namespace std;

// 类模板
template<class NameType, class AgeType = int>
class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void ShowPerson()
    {
        cout << "name:" << this->m_Name << " age:" << this->m_Age << endl;
    }
    NameType m_Name;
    AgeType m_Age;

};



void test1()
{
    // Person p1("孙悟空", 999);    // 错误，类模板没有自动类型推导的使用方式
    Person<string, int>p1("孙悟空", 999);
    p1.ShowPerson();

}

void test2()
{
    Person<string>p2("猪八戒", 666);   // 类模板在模板参数列表中可以有默认参数
    p2.ShowPerson();

}

int main()
{
    test1();
    test2();
    
    return 0;
}