/*
**作用：**让代码结构更加清晰

函数分文件编写一般有4个步骤

1.创建后缀名为.h的头文件
2.创建后缀名为.cpp的源文件
3.在头文件中写函数的声明
4.在源文件中写函数的定义
*/

#include<iostream>
#include<string>
#include<typeinfo>
#include"06-swap.h"
using namespace std;

// void swap(int a, int b);

// void swap(int a, int b)
// {
//     cout << "交换前：" << endl;
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
    
//     int temp = a;
//     a = b;
//     b = temp;

//     cout << "交换后：" << endl;
//     cout << "a=" << a << endl;
//     cout << "b=" << b << endl;
// }

int main()
{
    swap(10,20);

    return 0;
}