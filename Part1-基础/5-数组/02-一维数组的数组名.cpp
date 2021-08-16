/*
一维数组名称的用途：

可以统计整个数组在内存中的长度    sizeof(arr)
可以获取数组在内存中的首地址      cout << arr << endl
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int arr[5] = {1,2,3,4,5};

    // 1.可以统计整个数组在内存中的长度
    cout << sizeof(arr) << endl;     //5*4
    cout << sizeof(arr[0]) << endl;
    cout << "数组中元素个数为" << sizeof(arr) / sizeof(arr[0]) << endl;

    // 2.可以获取数组在内存中的首地址
    cout << "数组首地址为：" << (int)arr << endl;
    cout << "数组中第一个元素的地址为：" << (int)&arr[0] << endl;

    // 数组名是常量，不可以进行赋值操作
    // arr = 100;

    return 0;
}

