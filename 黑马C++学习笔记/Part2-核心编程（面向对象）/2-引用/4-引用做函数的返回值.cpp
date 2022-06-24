/*
作用：引用是可以作为函数的返回值存在的

注意：不要返回局部变量引用

用法：函数调用作为左值
*/

#include<string>
#include<iostream>
using namespace std;

int& test1()
{
    int a = 10;
    return a;
}

int& test2()
{
    static int a = 10;  // 静态变量，存放在全局区，全局区的数据在程序结束后系统释放
    return a;
}

int main()
{
    // 1.注意：不要返回局部变量引用
    // int &ref = test1();
    // cout << "ref=" << ref << endl;   // 第一次结果正确，是因为编译器做了保留
    // cout << "ref=" << ref << endl;   // a的内存已经释放

    int &ref = test2();
    cout << "ref=" << ref << endl;   
    cout << "ref=" << ref << endl;   

    // 2.用法：函数调用作为左值
    test2() = 1000;     // test2()返回的就是a的引用，将引用修改

    cout << "ref=" << ref << endl;   
    cout << "ref=" << ref << endl;

    return 0;
}