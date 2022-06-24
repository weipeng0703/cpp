/*
**作用：**函数传参时，可以利用引用的技术让形参修饰实参

**优点：**可以简化指针修改实参
*/

#include<string>
#include<iostream>
using namespace std;

// 交换函数
// 1.值传递
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "函数一中：" << endl;
    cout << a << endl;
    cout << b << endl;
}

// 2.地址传递
void swap2(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

    cout << "函数二中：" << endl;
    cout << *a << endl;
    cout << *b << endl;
}
// 3.引用传递
void swap3(int &a, int &b)      // &a &b相当于传入的 a  b 的别名
{
    int temp = a;
    a = b;
    b = temp;

    cout << "函数三中：" << endl;
    cout << a << endl;
    cout << b << endl;
}

int main()
{
    int a = 10, b = 20;

    cout << "最初：" << endl;
    cout << a << endl;
    cout << b << endl;

    // swap1(a,b);   // 值传递，形参不会修饰实参
    // swap2(&a,&b);   // 地址传递，形参会修饰实参
    swap3(a,b);   // 引用传递，形参会修饰实参

    cout << "实参：" << endl;
    cout << a << endl;
    cout << b << endl;


    return 0;
}