/*
所谓值传递，就是函数调用时实参将数值传入给形参
值传递时，如果形参发生改变，并不会影响实参
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 如果函数不需要返回值，声明的时候可以写void
// 定义两个数字交换的函数
void swap(int num1, int num2)
{
    cout << "交换前:" << endl;
    cout << "a=" << num1 << endl;
    cout << "b=" << num2 << endl;

    int temp = num1;
    num1 = num2;
    num2 = temp;
    // return;      // 返回值不需要的时，可以不写return

    cout << "交换后:" << endl;
    cout << "a=" << num1 << endl;
    cout << "b=" << num2 << endl;
}


int main()
{
    int a = 10, b = 20;

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    swap(a,b);

    // 当我们做值传递时，函数的形参发生变化，并不会影响实参
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;

    return 0;
}