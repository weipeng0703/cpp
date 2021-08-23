/*
深浅拷贝是面试经典问题，也是常见的一个坑

浅拷贝：简单的赋值拷贝操作
浅拷贝带来的问题：堆区（先进后出）重复释放。需要利用“深拷贝”就解决

深拷贝：在堆区重新申请空间，进行拷贝操作
    如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
private:
    /* data */
public:

    // 无参构造
    Person() 
    {
        cout << "Person的默认构造" << endl;
    }

    // 有参构造
    Person(int age, int height) 
    {
        m_Age = age;
    // 利用new操作符在堆区开辟数据
    // ​ 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

    // ​ 语法：new 数据类型
    // ​ 利用new创建的数据，会返回该数据对应的类型的 指针
        m_height = new int(height);
        cout << "Person的有参构造" << endl;
    }

    // // 自己实现一个拷贝构造函数，实现深拷贝
    Person(const Person &p)
    {
        cout << "Person的拷贝构造函数的调用" << endl;
        m_Age = p.m_Age;
        // m_height = p.m_height;   // 编译器默认实现的代码
        m_height = new int(*p.m_height);
    }

    // 析构函数
    ~Person() 
    {
        // 析构代码，用于将堆区开辟的数据做释放操作
        if (m_height != NULL)
        {
            delete m_height;
            m_height = NULL;
        }
        
        cout << "Person的析构" << endl;
    }
    
    int m_Age;
    int *m_height;
};

void test1()
{
    Person p1(18, 160);

    cout << "p1的年龄为：" << p1.m_Age << " p1的身高为：" << *p1.m_height << endl;

    Person p2(p1);      // 即 浅拷贝：编译器进行的默认的简单的赋值拷贝操作

    cout << "p2的年龄为：" << p2.m_Age << " p2的身高为：" << *p2.m_height << endl;

}



int main()
{
    test1();

    return 0;
}
