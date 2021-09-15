/*
类模板作用：
    建立一个通用类，类中的成员 数据类型可以不具体制定，用一个虚拟的类型来代表。
语法：
    template<typename T>
    类

解释：
    template — 声明创建模板
    typename — 表面其后面的符号是一种数据类型，可以用class代替
    T — 通用的数据类型，名称可以替换，通常为大写字母
*/

#include<string>
#include<iostream>
using namespace std;

// 类模板
template<class NameType, class AgeType>
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
    Person<string, int> p1("孙悟空", 999);
    p1.ShowPerson();

}

int main()
{
    test1();
    
    return 0;
}