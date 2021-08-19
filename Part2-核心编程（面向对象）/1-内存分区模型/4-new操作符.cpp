/*
​ C++中利用new操作符在堆区开辟数据

​ 堆区开辟的数据，由程序员手动开辟，手动释放，释放利用操作符 delete

​ 语法：new 数据类型

​ 利用new创建的数据，会返回该数据对应的类型的指针
*/

#include<string>
#include<iostream>
using namespace std;

int * func()
{
    // 在堆区创建一个整型数据
    int *p = new int(10);   // new返回给数据类型的指针
    return p;
}

// 1.new的基本语法
void test01()
{
    int *p = func();
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;  // 堆区的数据由程序员管理开辟，程序员管理释放
    
    // 释放堆区的数据
    delete p;
    cout << *p << endl;   // 内存已经被释放，再次访问就是非法操作，会报错(生成乱码)
}

// 2.在堆区利用new开辟一个数组
void test02()
{
    // 创建一个10个整型数据的数组
    int *arr = new int[10];  // [] 代表数组有10个元素，返回数组的首地址

    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 100;   // 给10个元素赋值   100~109
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << endl;
    }

    // 释放堆区数组
    // 释放数组的时候要加[]

    delete[] arr;
    
}

int main()
{
    test01();

    test02();

    return 0;
}