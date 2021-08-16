#include<iostream>
#include<string>
#include<typeinfo>
#include"06-swap.h"
using namespace std;


void swap(int a, int b)
{
    cout << "交换前：" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    int temp = a;
    a = b;
    b = temp;

    cout << "交换后：" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}
