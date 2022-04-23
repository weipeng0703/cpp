/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-23 10:51:09
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-23 10:56:06
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
// #include<priority_queue>
using namespace std; 

/*
1. stoi函数
作用：
将 n 进制的字符串转化为十进制
用法
stoi（字符串，起始位置，n进制（默认10进制）），将 n 进制的字符串转化为十进制
举例：
stoi(str, 0, 2); //将字符串 str 从 0 位置之后的数字的 2 进制数，转换为十进制

2. to_string()函数
包含在头文件#include<string>
功能：
将数值转化为字符串。返回对应的字符串。
*/ 

#include<iostream>
#include<string>
using namespace std;

int main() {
    string str = "1200";
    int a = stoi(str);//默认是10进制的，将 10 进制的字符串1200转化为十进制数值
    int b = stoi(str, 0,8);//8进制的1200转换成10进制
    cout <<"a(10进制的字符串1200转化为十进制数值):" <<a << endl;
    cout <<"b(8进制的1200转换成10进制):" <<b << endl;

    string pi = "pi is " + to_string(3.1415926);
    float pf = 42430.23;
    string float_str = to_string(pf) + " is a number";
    
    cout << pi << endl;
    cout << float_str << endl;
    return 0;
}

