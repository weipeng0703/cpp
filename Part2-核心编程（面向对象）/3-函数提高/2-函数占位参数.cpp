/*
C++中函数的形参列表里可以有占位参数，用来做占位，调用函数时必须填补该位置

语法： 返回值类型 函数名 (数据类型){}

在现阶段函数的占位参数存在意义不大，但是后面的课程中会用到该技术
*/
#include<iostream>
#include<string>
using namespace std;

void func(int a,int)   // 占位参数可以有默认参数
{
    cout << "this is a func!" << endl;

}

int main()
{
    func(10,10);

    return 0;
}