/*
所有指针类型在32位操作系统下是4个字节
所有指针类型在64位操作系统下是8个字节
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int a = 10;
    
    // // 定义指针变量  数据类型 * 变量名
    // int *p;

    // // 让指针记录变量a的地址
    // p = &a;

    int *p = &a;
    cout << *p << endl;
    
    cout << sizeof(int *) << endl;
    cout << sizeof(float *) << endl;
    cout << sizeof(double *) << endl;
    cout << sizeof(char *) << endl;
    cout << sizeof(p) << endl;

    return 0;
}