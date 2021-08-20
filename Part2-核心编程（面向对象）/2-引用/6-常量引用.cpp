/*
**作用：**常量引用主要用来修饰形参，防止误操作

在函数形参列表中，可以加const修饰形参，防止形参改变实参
*/
#include<string>
#include<iostream>
using namespace std;

void ShowValue1(int &val)
{
    val = 1000;
    cout << "函数1中" << endl;
    cout << "val=" << val << endl;
}
// 该函数只是为了显示数字，并不想将值进行修改，所以加上const防止误操作
void ShowValue2(const int &val)
{
    // val = 1000;   // 此时val便不能再修改了
    cout << "函数2中" << endl;
    cout << "val=" << val << endl;
}

int main()
{
    // int a = 10;
    // int &ref = 10;   // 错误，引用必须引用一块合法的内存空间

    // 加上const之后编译器自动将代码修改为： int temp = 10; const int &ref = temp;
    const int &ref = 10;  

    // ref = 20;   // 加入const之后变为只读，不能修改

    
    int a = 100;

    // ShowValue1(a);
    // cout << "运行完函数1后：" << endl;
    // cout << "a=" << a <<endl;

    ShowValue2(a);
    cout << "运行完函数2后：" << endl;
    cout << "a=" << a <<endl;

    return 0;

}