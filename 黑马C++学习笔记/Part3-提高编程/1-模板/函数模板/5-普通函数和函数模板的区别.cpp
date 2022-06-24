/*
普通函数与函数模板区别：
    普通函数调用时可以发生自动类型转换（隐式类型转换）
    函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
    如果利用显示指定类型的方式，可以发生隐式类型转换
*/

#include<string>
#include<iostream>
using namespace std;
// 普通的加法函数
int Add(int a, int b)
{
    return a+b;


}

// 加法的函数模板
 template<typename T>
 int Add1(T a, T b)
 {
    return a + b; 

 }

void test1()
{

    int a = 10;
    int b = 20;
    char c = 'c';   // c的ASCII码数为99
    // cout << Add(a, c) << endl;   // 隐式类型转换，将c转为其对应的ASCII码

    // 1.自动类型推导
    // cout << Add1(a,b) << endl;   // 正确
    // cout << Add1(a,c) << endl;   // 错误

    // 2.显式指定类型
    cout << Add1<int>(a,b) << endl;   // 正确
    cout << Add1<int>(a,c) << endl;   // 正确
}
int main()
{
    test1();


    return 0;
}
