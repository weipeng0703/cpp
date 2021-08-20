/*
1.引用必须初始化
2.引用在初始化后，不可以改变
*/

#include<string>
#include<iostream>
using namespace std;

int main()
{
    // 引用必须初始化
    int a = 10;
    cout << a << endl;

    int &b = a;
    cout << b << endl;

    b = 20;

    cout << b << endl;
    cout << a << endl;

    // 引用在初始化后不能改变

    int c = 30;
    b = c;   // 赋值操作，不是更改引用
    // int &b = c;   // 错误语法

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;


    return 0;
}