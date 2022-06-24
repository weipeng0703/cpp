#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 定义一个加法函数，实现两个数相加

int add(int num1, int num2)   // 函数定义时，num1与num2并无真实数据，称为形参
{
    int sum = num1 + num2;
    return sum;
}

int main()
{
    int a = 10, b = 10;

    // 函数调用语法：函数名称（参数）
    // a和b为实际的参数，简称实参
    // 调用函数时，实参的值会传递给形参
    cout << add(a,b) << endl;

    return 0;
}