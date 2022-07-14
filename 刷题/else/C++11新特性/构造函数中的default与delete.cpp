/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-14 09:46:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-14 09:55:42
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
// #include<priority_queue>
using namespace std;

// default
/*
// default关键字可以显式要求编译器生成合成构造函数，防止在调用时相关构造函数类型没有定义而报错
class CString {
public:
    CString() = default; //语句1
    //构造函数
    CString(const char* pstr) : _str(pstr){}
    //析构函数
    ~CString(){}
public:
    string _str;
};

int main() {
    auto a = new CString(); //语句2
    cout << "Hello World" <<endl;
    return 0; 
}
// 如果没有加语句1，语句2会报错，表示找不到参数为空的构造函数，将其设置为default可以解决这个问题
*/

// delete
// delete关键字可以删除构造函数、赋值运算符函数等，这样在使用的时候会得到友善的提示
/*
class CString {
public:
    void* operator new(size_t) = delete;  //这样不允许使用new关键字
    //析构函数
    ~CString(){}
};
int main() {
    auto a = new CString(); //语句1
    cout << "Hello World" <<endl;
    return 0; 
}*/