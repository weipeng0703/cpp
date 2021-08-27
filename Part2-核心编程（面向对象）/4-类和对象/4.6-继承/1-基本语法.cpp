/*
继承
定义某些类时，下级别的成员除了拥有上一级的共性，还有自己的特性。
这个时候我们就可以考虑利用继承的技术——减少重复代码

语法
class 子类 : 继承方式 父类
{

};

子类也称为派生类
父类也称为基类

派生类中的成员，包含两大部分：

    一类是从基类继承过来的，一类是自己增加的成员。

从基类继承过过来的表现其 共性，而新增的成员体现了其 个性。
*/
#include<iostream>
#include<string>
using namespace std;

// 普通实现页面
// JAVA页面
// class JAVA
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录......" << endl;

//     }

//     void footer()
//     {
//         cout << "帮助中心，交流合作......" << endl;

//     }

//     void left()
//     {
//         cout << "C++，JAVA，PYTHON......" << endl;

//     }

//     void content()
//     {
//         cout << "JAVA视频......" << endl;

//     }

// };

// // python页面
// class python    
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录......" << endl;

//     }

//     void footer()
//     {
//         cout << "帮助中心，交流合作......" << endl;

//     }

//     void left()
//     {
//         cout << "C++，JAVA，PYTHON......" << endl;

//     }

//     void content()
//     {
//         cout << "python视频......" << endl;

//     }

// };

// // C++页面
// class cpp
// {
// public:
//     void header()
//     {
//         cout << "首页、公开课、登录......" << endl;

//     }

//     void footer()
//     {
//         cout << "帮助中心，交流合作......" << endl;

//     }

//     void left()
//     {
//         cout << "C++，JAVA，PYTHON......" << endl;

//     }

//     void content()
//     {
//         cout << "C++视频......" << endl;

//     }

// };


// 继承实现
class BasePages
{
public:
    void header()
    {
        cout << "首页、公开课、登录......" << endl;

    }

    void footer()
    {
        cout << "帮助中心，交流合作......" << endl;

    }

    void left()
    {
        cout << "C++，JAVA，PYTHON......" << endl;

    }

    void content()
    {
        cout << "JAVA视频......" << endl;

    }

};

// JAVA页面
class JAVA : public BasePages
{
public:
    void content()
    {
        cout << "JAVA视频......" << endl;

    }

};

// python页面
class python : public BasePages
{
public:
    void content()
    {
        cout << "python视频......" << endl;

    }

};

// CPP页面
class CPP : public BasePages
{
public:
    void content()
    {
        cout << "CPP视频......" << endl;

    }

};

void test1()
{
    JAVA java;
    cout << "这是JAVA页面：" << endl;
    java.header();
    java.footer();
    java.left();
    java.content();

    python python;
    cout << "--------------------------------\n这是python页面：" << endl;
    python.header();
    python.footer();
    python.left();
    python.content();

    CPP cpp;
    cout << "--------------------------------\n这是cpp页面：" << endl;
    cpp.header();
    cpp.footer();
    cpp.left();
    cpp.content();
}

int main()
{
    test1();

    return 0;
}