/*
常函数：

    成员函数后加const后我们称为这个函数为常函数
    常函数内不可以修改成员属性
    成员属性声明时加关键字mutable后，在常函数中依然可以修改

常对象：

    声明对象前加const称该对象为常对象
    常对象只能调用常函数
*/
#include<iostream>
#include<string>
using namespace std;

class Person
{
public:
	Person() 
    {
		m_A = 0;
		m_B = 0;
	}
    void func() 
    {

    }

    void ShowPerson() const  // 加上const之后，除了指针指向无法修改，指向的值也无法修改了
        {
        // this指针的本质是一个 指针常量，其修饰常量，所以指针的指向无法修改
        // 即 Person * const this 
        // this->m_A = 100;
        this->m_B = 100;

        // this = NULL;    // this指针不可修改指向

    }

    int m_A;
    mutable int m_B;   // 特殊变量，需要即使在常函数中也可以修改其值

};


void test1()
{
    Person p;
    // cout << "p的年龄为:" << p.ShowPerson() << endl;

}

void test2()
{
    const Person person;  // 在对象前加const，变为常对象

    // p.m_A = 100;
    person.m_B = 100;  // m_B为特殊值，在常对象下也可以修改

    // 常对象只能调用常函数，不能调用普通函数，因为普通成员函数可以修改属性
    person.ShowPerson();
    // person.func();   // 错误

}


int main()
{
    // test1();
    test2();

    return 0;
}