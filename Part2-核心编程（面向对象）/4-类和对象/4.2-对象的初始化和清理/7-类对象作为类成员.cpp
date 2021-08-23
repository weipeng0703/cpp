/*
C++类中的成员可以是另一个类的对象，我们称该成员为 对象成员

例如：

    class A {}
    class B
    {
        A a；
    }

B类中有对象A作为成员，A为对象成员

那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？
*/
#include<iostream>
#include<string>
using namespace std;

// 手机类
class Phone
{
private:


    /* data */
public:

    string m_Pname;

    Phone(string pName) 
    {
        cout << "Phone构造函数的调用" << endl;
        m_Pname = pName;
    }


    ~Phone() 
    {
        cout << "Phone析构函数的调用" << endl;
    }
};


class Person
{
private:
    /* data */
public:

    string m_Name;
    Phone m_Phone;

    Person(string name, string pName):m_Name(name), m_Phone(pName)
    {
        cout << "Person构造函数的调用" << endl;
    }

    ~Person() 
    {
        cout << "Person析构函数的调用" << endl;
    }
};

// 当其他类对象作为本类成员，构造时候先构造类对象，再构造自身；
// 析构的顺序生好相反

void test1()
{
    Person p("张三", "苹果12");
    cout << p.m_Name << "使用" << p.m_Phone.m_Pname <<endl;

}

int main()
{
    test1();

    return 0;
}
