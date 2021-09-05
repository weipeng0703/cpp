/*
调用规则如下：
    1.如果函数模板和普通函数都可以实现，优先调用  普通函数
    2.可以通过空模板参数列表来强制调用函数模板
    3.函数模板也可以发生重载
    4.如果函数模板可以产生更好的匹配,优先调用函数模板

注：若提供了函数模板，最好就不要提供普通函数，否则容易出现二义性
*/

#include<string>
#include<iostream>
using namespace std;
// 普通函数
void MyPrint(int a, int b)
{
    cout << "调用的普通函数" << endl;

}

// 函数模板
template<class T>
void MyPrint(T a, T b)
{
    cout << "调用的函数模板" << endl;

}

template<class T>
void MyPrint(T a, T b, T c)
{
    cout << "调用的重载函数模板" << endl;

}

void test1()
{
    int a = 10;
    int b = 20;
    // MyPrint(a, b);   // 1.优先调用普通函数

    // 2.通过空模板参数列表，强制调用函数模板
    // MyPrint<>(a,b);

    // MyPrint<>(a, b, 200);   // 3.函数模板也可以发生重载

    // 4.如果函数模板可以产生更好的匹配,优先调用函数模板
    char c1 = 'a';
    char c2 = 'b';
    MyPrint(c1, c2);

}
int main()
{
    test1();


    return 0;
}
