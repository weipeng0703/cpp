/*
作用： 告诉编译器函数名称及如何调用函数。函数的实际主体可以单独定义。

函数的声明可以多次，但是函数的定义只能有一次
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 比较函数：实现两个整型数字比较，返回较大值
int max(int a, int b)
{
    return a > b? a : b;
}

// 函数声明，提前告知编译器函数的存在
int max(int a, int b);

int main()
{
    int a =10, b = 20;

    cout << max(a,b) << endl;
    return 0;
}