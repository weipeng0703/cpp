/*
1.引用作为重载条件
2.函数重载碰到函数默认参数
*/
#include<iostream>
#include<string>
using namespace std;

// 1.引用作为重载条件
void func(int &a)    // int &a = 10;不合法
{
    cout << "func(int &a)调用" << endl;
}

void func(const int &a)   // const int &a = 10;合法
{
    cout << "func(const int &a)调用" << endl;
}

// 2.函数重载碰到函数默认参数

void func2(int a,int b = 10)
{
    cout << "func2(int a,int b)调用" << endl; 
}

void func2(int a)
{
    cout << "func2(int a)调用" << endl; 
}

int main()
{
    // int a = 10;
    // func(a);

    // func(10);

    func2(10,10);
    // func2(10);  // 上述两个函数均可以带入,产生二义性,编译器傻了.尽量避免默认参数的情况

    return 0;
}