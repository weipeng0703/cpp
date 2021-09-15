/*
**作用：**利用指针作函数参数，可以修改实参的值

总结：如果不想修改实参，就用值传递，如果想修改实参，就用地址传递
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 实现两个数字交换
void swap1(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    cout << "值传递交换后：" << endl;
    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
}

void swap2(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    cout << "地址传递交换后：" << endl;
    cout << "a=" << *p1 << endl;
    cout << "b=" << *p2 << endl;
}

int main()
{   
    // 值传递
    int a = 10,b = 20;
    swap1(a,b);

    // cout << "a=" << a << endl;
    // cout << "b=" << b << endl;

    // 地址传递
    // 如果是地址传递，可以修饰实参
    swap2(&a,&b);

    cout << "a=" << a << endl;
    cout << "b=" << b << endl;
    
    return 0;
}