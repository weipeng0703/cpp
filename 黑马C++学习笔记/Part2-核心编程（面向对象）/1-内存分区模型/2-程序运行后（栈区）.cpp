/*
栈区：

​ 由编译器自动分配释放, 存放函数的参数值,局部变量等

​ 注意事项：不要返回 局部变量 的地址，栈区开辟的数据由 编译器 自动释放
*/

#include<string>
#include<iostream>
using namespace std;

int* func(int b)      // 形参数据也会放在栈区
{
    b = 100;
    int a = 10;
    return &a;
}

int main()
{
    int * p = func(1);

    cout << *p << endl;   // 第一次可以打印正确的数字是因为编译器做了保留
    cout << *p << endl;   // 第二次不会保留

    return 0;
}