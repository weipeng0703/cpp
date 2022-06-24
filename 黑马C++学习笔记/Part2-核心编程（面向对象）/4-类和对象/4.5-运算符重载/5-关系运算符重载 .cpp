/*
**作用：**重载关系运算符，可以让两个自定义类型对象进行对比操作

大于，小于，不等情况类似
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_age = age;

    }

    // 关系运算符重载
    bool operator==(Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_age == p.m_age)
        {
            return true;
        }
        else
        {
            return false;
        }
        
        

    }
   string m_Name;
   int m_age;
};



void test1()
{
    Person p1("Tom", 18);

    Person p2("Tom", 18);

    if (p1 == p2)
    {
        cout << "p1与p2相等" << endl;
    }
    else
    {
        cout << "p1与p2不相等" << endl;
    }
    
    

}

int main()
{
    test1();

    return 0;
}