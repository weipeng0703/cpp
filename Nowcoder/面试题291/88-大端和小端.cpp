// 题目
/*
什么是大端小端以及如何判断大端小端
*/

// 解答
/*
大端是指低字节存储在高地址；小端存储是指低字节存储在低地址。

可以根据联合体来判断该系统是大端还是小端。因为联合体变量总是从低地址存储。
*/
#include<iostream>
using namespace std;

int func()
{

    union test
    {
        int i;

        char c;
    };
    
    test t;
    t.i = 1;

    // 如果是大端，t.c为0x00，t.c不等于1，返回0
    // 如果是小端，t.c为0x01，t.c等于1，返回1

    return (t.c == 1);


}

int main()
{

    // int flag;

    if (func == 0)
    {
        cout << "大端" << endl;
    }
    else 
    {
        cout << "小端" << endl;
    }
    

    return 0;
}