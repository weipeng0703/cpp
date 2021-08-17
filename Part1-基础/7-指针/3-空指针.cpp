/*
空指针：指针变量指向内存中编号为0的空间
**用途：**初始化指针变量
**注意：**空指针指向的内存是不可以访问的
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{   
    // 指针变量p指向内存地址编号为0的空间
    int *p = NULL;

    // 空指针不可以进行访问
    // 0·255编号之间的内存是系统占用的，因此不可以访问
    *p = 10;
    cout << *p << endl;

    return 0;
}