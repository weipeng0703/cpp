/*
7.1 概念：
指针的作用： 可以通过指针间接访问内存
内存编号是从0开始记录的，一般用十六进制数字表示
可以利用指针变量保存地址

7.2 指针变量的定义和使用
指针变量定义语法： 数据类型 * 变量名；
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int a = 10;
    
    // 定义指针变量  数据类型 * 变量名
    int *p;

    // 让指针记录变量a的地址
    p = &a;
    cout << "a的地址为：" << &a << endl;
    cout << "指针p为：" << p << endl;

    // 使用指针：可以通过解引用（指针前加*，代表指针指向的内存中的数据）的方式来找到指针指向的内存
    cout << "指针p解引用后的结果为：" << *p << endl;
    cout << "变量a为：" << a << endl;

    *p = 1000;
    cout << "指针p解引用后的结果为：" << *p << endl;
    cout << "变量a为：" << a << endl;

    cout << "此时指针p为：" << p << endl;
    cout << "此时a的地址为：" << &a << endl;

    return 0;
}