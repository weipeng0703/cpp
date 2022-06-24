/*
**作用： **给变量起别名

语法： 数据类型 &别名 = 原名
*/

#include<string>
#include<iostream>
using namespace std;

int main()
{
    int a = 10;
    cout << a << endl;

    int &b = a;
    cout << b << endl;

    b = 20;

    cout << b << endl;
    cout << a << endl;


    return 0;
}