/*
1.查看二维数组所占内存空间
2.获取二维数组首地址
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    // 1.查看二维数组所占内存空间

    int arry[2][3] = 
    {
        {1,2,3},
        {4,5,6}
    };

    cout << "二维数组所占内存空间大小为" << sizeof(arry) << endl;
    cout << "二维数组第一行所占内存空间大小为" << sizeof(arry[0]) << endl;
    cout << "二维数组第一个元素所占内存空间大小为" << sizeof(arry[0][0]) << endl;
    cout << "二维数组的行数为" << sizeof(arry) / sizeof(arry[0]) << endl;
    cout << "二维数组的列数为" << sizeof(arry[0]) / sizeof(arry[0][0]) << endl;


    // 2.获取二维数组首地址

    cout << "二维数组的首地址为" << arry << endl;
    // cout << "二维数组的首地址为" << (int)arry << endl;

    cout << "二维数组第一行的首地址为" << arry[0] << endl;
    // cout << "二维数组第一行的首地址为" << (int)arry[0] << endl;

    cout << "二维数组第二行的首地址为" << arry[1] << endl;

    cout << "二维数组第一个元素的首地址为" << &arry[0][0] << endl;   //&为取值符
    cout << "二维数组第二个元素的首地址为" << &arry[0][1] << endl;   //&为取值符


    return 0;
}