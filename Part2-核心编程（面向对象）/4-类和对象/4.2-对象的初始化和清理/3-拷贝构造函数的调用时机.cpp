/*
C++中拷贝构造函数调用时机通常有三种情况

    使用一个已经创建完毕的对象来初始化一个新对象
    值传递的方式给函数参数传值
    以值方式返回局部对象

*/
#include<iostream>
#include<string>
using namespace std;

// 1.使用一个已经创建完毕的对象来初始化一个新对象
// 2.值传递的方式给函数参数传值
// 3.以值方式返回局部对象

class Person
{
private:
    /* data */
public:
    Person() // 默认构造函数
    {
        cout << "Person 默认构造函数的调用" << endl;
    }

    Person(int age)  // 有参构造函数
    {
        cout << "Person 有参构造函数的调用" << endl;
        m_Age = age;
    }

    Person(const Person &p)   // 拷贝构造函数
    {
        cout << "Person 拷贝构造函数的调用" << endl;
        m_Age = p.m_Age;
    }
    
    ~Person()   // 析构函数 
    {
        cout << "Person 析构函数的调用" << endl;
    }

    int m_Age;
};

// 1.使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
    Person p1(20);
    Person p2(p1);

    cout << "p2的年龄为：" << p2.m_Age << endl;
}

// 2.值传递的方式给函数参数传值
void doWork(Person p)
{

}
void test2()
{
    Person p;    // 若只有这一行代码，只会调用默认构造函数
    doWork(p);   // 实参传给形参时，调用一个拷贝构造函数，上面的p会根下面的p拷出一个新的数据
}

// 3.以值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << &p1 << endl;
    return p1;      // 返回时，会根据这个p1产生一个新的对象返回给test3.
    // 在doWork2()函数调用结束时，p1的默认构造函数和拷贝构造函数的析构函数进行回收
}
void test3()
{
    Person p = doWork2();   // 此处的p即为doWork2()返回的p1
    cout << &p << endl;
}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}