/*
c++编译器至少给一个类添加4个函数

    默认构造函数(无参，函数体为空)
    默认析构函数(无参，函数体为空)
    默认拷贝构造函数，对属性进行值拷贝
    赋值运算符 operator=, 对属性进行值拷贝
如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝问题
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
    Person(int age)
    {
        m_Age = new int(age);
    }

    ~Person()
    {
        if(m_Age != NULL)
        {

            delete m_Age;
            m_Age = NULL;

        }

    } 

    // 重载赋值运算符
    Person operator=(Person &p)
    {
        // 编译器提供的是浅拷贝
        // m_Age = p.m_Age;

        // 应该先判断是否有属性在堆区，若有先释放干净，然后再深拷贝
        if (m_Age != NULL)
        {
            delete m_Age;
            m_Age = NULL;
        }
        // 深拷贝
        m_Age = new int(*p.m_Age);

        // 返回对象本身
        return *this;
    }

    int *m_Age;   // 年龄真实的数据开辟到堆区
};



void test1()
{
    Person p1(10);

    cout << "p1的年龄为:" << *(p1.m_Age) << endl;

    Person p2(20);

    cout << "赋值之前：p2的年龄为:" << *(p2.m_Age) << endl;

    p2 = p1;   // 赋值操作

    cout << "赋值之后：p2的年龄为:" << *(p2.m_Age) << endl;

    Person p3(30);

    // p3 = p2 = p1;   // 这个地方应该是没有问题的
    cout << "赋值之后：p3的年龄为:" << *(p3.m_Age) << endl;

}

int main()
{
    test1();

    return 0;
}