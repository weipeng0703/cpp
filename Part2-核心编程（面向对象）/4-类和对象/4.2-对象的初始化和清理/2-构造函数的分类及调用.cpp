/*
两种分类方式：

    ?按参数分为： 有参构造和无参构造
    按类型分为： 普通构造和拷贝构造

三种调用方式：

    ?括号法

    ?显示法

    ?隐式转换法

*/
#include<iostream>
#include<string>
using namespace std;
class Person
{
private:
  
    /* data */
public:
    // 无参构造（默认构造）
    Person() 
    {
        cout << "Person 无参构造函数调用" << endl;
    }
    // 有参构造
    Person(int a) 
    {
        age = a;
        cout << "Person 有参构造函数调用" << endl;
    }
    // 拷贝构造函数（除了这种构造方式，其余均为普通构造）
    Person(const Person &p)
    {
        // 将传入的人身上的所有属性，拷贝到我身上
        age = p.age;
        cout << "Person 拷贝构造函数调用" << endl;

    }
    ~Person() 
    {
        cout << "Person 析构函数调用" << endl;
    }
    
    int age;
};

// 调用
void test1()
{
    // 1.括号法

    // 注意事项1：
    // 调用默认构造函数的时候不要加()
    // 因为编译器会将Person p1()看作一个类似void func()一样的函数声明
    // Person p1();
    
    // Person p1;  // 默认构造函数的调用；
    // Person p2(10);  // 有参构造函数的调用；
    // Person p3(p2);  // 拷贝构造函数的调用；


    // cout << "p2的年龄为：" << p2.age << endl;
    // cout << "p3的年龄为：" << p3.age << endl;

    // 2.显示法
    // Person p1;  // 默认构造
    // Person p2 = Person(10);   // 有参构造
    // Person p3 = Person(p2);

    // Person(10);  // 匿名对象  特点：当前执行结束后，系统会立刻回收匿名对象
    // cout << "aaaaaa" << endl;

    // 注意事项2：
    // 不要利用拷贝构造函数初始化匿名对象,编译器会认为 Person(p3) == Person p3,
    // 编译器会认为这是个对象声明
    // Person(p3);

    // 3.隐式转换法
    Person p1;
    Person p4 = 10;   // 相当于一个有参构造的调用
    Person p5 = p4;   // 相当于一个拷贝构造的调用
}



int main()
{
    test1();

    return 0;
}