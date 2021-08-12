// 常量的作用是用于记录程序中不可更改的数据
// C++定义常量的两种形式：
// 1.#define 宏常量
//   #define 常量名 常量值
//   通常定义在文件上方，表示一个常量
// 2.const修饰的变量
//   const 数据类型 常量名 = 常量值
//   通常在变量定义前加关键字const，修饰该变量为常量，不可更改

//1、宏常量
# define Day 7
#include<iostream>
using namespace std;

int main() 
{
    // int Day = 14;  //宏常量不能修改
    cout << "一周共" << Day << "天" << endl;

    const int month = 12;
    // month  = 13;  //const常量也不能修改
    cout << "一年共" << month << "月" << endl;

	return 0;
}
