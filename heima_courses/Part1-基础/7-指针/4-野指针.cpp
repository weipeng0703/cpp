/*
野指针：指针变量指向非法的内存空间

空指针和野指针都不是我们申请的空间，因此不要访问。
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{   
    int *p = (int *)0x1100;   //指向了一块内存，但是没有直接访问它的权限

    cout << *p << endl;

    return 0;
}