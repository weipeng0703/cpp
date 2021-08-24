/*
通过4.3.1我们知道在C++中成员变量和成员函数是分开存储的

每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共用一块代码

那么问题是：这一块代码是如何区分那个对象调用自己的呢？

c++通过提供特殊的对象指针，this指针，解决上述问题。this指针指向被调用的成员函数所属的对象

this指针是隐含每一个非静态成员函数内的一种指针

this指针不需要定义，直接使用即可

this指针的用途：

当形参和成员变量同名时，可用this指针来区分
在类的非静态成员函数中返回对象本身，可使用return *this
*/
#include<iostream>
#include<string>
using namespace std;

// 1.解决名称冲突
class Person
{
private:
    /* data */
public:
    Person(int age) 
    {
        // this指针指向被调用的成员函数所属的对象
        // 在这儿即指向（Person（）函数）所属的class类的对象age
        this->age = age;
    }

    // 如果使用Person值返回类型的话，每次都会创建一个新的对象,即每次都返回加完一次10的p2
    // Person PersonAddAge(Person &p)
    Person& PersonAddAge(Person &p)
    {
        this->age += p.age;

        // this是指向p2的指针，那么*this即p2本体
        return *this;

    }

    ~Person() {}

    int age;
};

void test1()
{
    Person p1(18);
    cout << "p1的年龄为：" << p1.age << endl;

}

// 2.返回对象本身用*this

void test2()
{
    Person p1(10);
    Person p2(10);

    // 链式编程
    p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

    cout << "p1的年龄为：" << p1.age << endl;
    cout << "p2的年龄为：" << p2.age << endl;

}


int main()
{
    // test1();
    test2();

    return 0;
}