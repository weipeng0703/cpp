/*
const修饰指针有三种情况

1.const修饰指针 — 常量指针
2.const修饰常量 — 指针常量
3.const既修饰指针,又修饰常量

对于前两种情况，const修饰的是谁，谁就可以改
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{   
    int a = 10;
    int b = 10;
    // 1.const修饰 指针 — 常量指针:指针指向的值不可以改，指针的指向可以改 

    int *p1 = &a;
    const int *p1 = &a;

    // *p1 = 20;   //错误
    p1 = &b;    //正确


    // 2.const修饰 常量 — 指针常量:指针的指向不可以改，指针指向的值可以改

    int * const p2 = &a;
    *p2 = 100;   //正确
    // p2 = &b;     //错误

    // 3.const既修饰指针，又修饰常量:指针的指向和指针指向的值都不可以改

    const int * const p3 = &a;
    // *p3 = 100;   //错误
    // p3 = &b;     //错误

    return 0;
}