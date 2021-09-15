/*
**作用：**利用指针访问数组中元素
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{   
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout << "数组中第一个元素为：" << arr[0] << endl;

    int *p = arr;   //arr就是数组的首地址，对其解引用
    cout << "利用指针访问数组中第一个元素为：" << *p << endl;

    p++;   //将指针向后偏移其所在系统的默认字节
    cout << "利用指针访问数组中第二个元素为：" << *p << endl;

    // 利用指针遍历数组
    cout << "利用指针遍历数组:" << endl;
    int *p2 = arr;
    for (int i = 0; i < 10; i++)
    {
        cout << *p2 << endl;
        p2++;
    }
    
    
    return 0;
}