/*
局限性：
    模板的通用性并不是万能的

例如：
template<class T>
void f(T a, T b)
{ 
    a = b;
}
在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了

再例如：

template<class T>
void f(T a, T b)
{ 
    if(a > b) { ... }
}

在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行

因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
*/

#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }


    string m_Name;
    int m_Age;

};
// 对比两个数据是否相等
template<class T>
bool Compare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }

}


// void test1()
// {
//     int a = 10 , b = 20;
//     bool flag = Compare(a, b);

//     if (flag)
//     {
//         cout << "a与b相等" << endl;
//     }
//     else
//     {
//         cout << "a与b不相等" << endl;
//     }
    
    

// }

// 利用具体化Person的版本实现代码，具体化优先调用
template<>bool Compare(Person &p1, Person &p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

void test2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 20);

    bool flag = Compare(p1, p2);

    if (flag)
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
    // test1();
    test2();

    return 0;
}
