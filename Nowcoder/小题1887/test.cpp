#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std;

int main()
{
    int a = 248, b = 4;
    int const c = 21;

    *c= 32;
    return 0;
}

// A选项 
// static成员变量可在类定义内初始化，这是有可能的。
// 普通的static成员类内定义，类外初始化
// const staic 可以类内初始化。
// B选项：
// const成员变量必须在构造函数的初始化列表中初始化？//不对吧，const可以在定义时初始化啊！
// //在类定义的时候，就对const成员变量进行赋值,可能使得所有的对象const变量都是同一个值，且不能更改
// D选项： 
// 数组可以用大括号初始化，且不会出warning。如：
// class A{
//     private:
//         int a[100];
//     public:
//         A(int a0,int a1,int a2):a{a0,a1,a2}{
//         }
// }