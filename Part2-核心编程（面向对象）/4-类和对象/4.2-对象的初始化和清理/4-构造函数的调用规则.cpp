/*
4.2.4 构造函数调用规则
默认情况下，c++编译器至少给一个类添加3个函数

    1．默认构造函数(无参，函数体为空)

    2．默认析构函数(无参，函数体为空)

    3．默认拷贝构造函数，对属性进行值拷贝

构造函数调用规则如下：

    如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造

    如果用户定义拷贝构造函数，c++不会再提供其他构造函数

*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:

    // Person() 
    // {
    //     cout << "Person的默认构造" << endl;
    // }

    Person(int age) 
    {
        cout << "Person的有参构造" << endl;
        m_Age = age;
    }

    Person(const Person &p)
    {
        cout << "Person的拷贝构造" << endl;
        m_Age = p.m_Age;

    }

    ~Person() 
    {
        cout << "Person的析构" << endl;
    }
    
    int m_Age;
};

// void test1()
// {
//     Person p;
//     p.m_Age = 18;
//     Person p2(p);   //上面没有写拷贝构造，但是编译器仍然可以自动构造一个拷贝函数
//     cout << "P2的年龄为：" << p2.m_Age << endl;
// }

void test2()
{
    // 如果用户定义有参构造函数，c++不再提供默认无参构造，但是会提供默认拷贝构造
    // 所以该语句错误
    // Person p;   

    Person p1(28);

    Person p2(p1);
    cout << "P2的年龄为：" << p2.m_Age << endl;
}

// 如果用户定义拷贝构造函数，c++不会再提供其他构造函数
void test3()
{ 
    // Person p;    // 没有默认构造参数
    // Person p2(18);    // 没有有参构造参数

}


int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}
