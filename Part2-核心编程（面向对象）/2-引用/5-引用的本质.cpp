/*
本质：引用的本质在c++内部实现是一个指针常量.

C++推荐用引用技术，因为语法方便，引用本质是指针常量，
但是所有的指针操作编译器都帮我们做了
*/
#include<string>
#include<iostream>
using namespace std;

// 函数例子同理
void func(int& ref)
{
    ref = 100;      // ref是引用，转换为 *ref = 100

}

int main()
{
    int a = 10;

    // 编译器发现引用语法后会自动替换为 int * const ref  = &a 这个指针常量; 
    // 指针常量的指针指向不能改，也间接说明引用不可更改
    int &ref = a;

    // 内部发现ref是引用，
    // 自动帮我们转换为 *ref = 20（解引用——指针常量指向的值可以修改）
    ref = 20;   

    cout << "a=" << a << endl;
    cout << "ref=" << ref << endl;

    func(a);

    return 0;
}