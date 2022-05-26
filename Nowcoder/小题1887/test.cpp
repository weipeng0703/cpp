/*
 * @Descripttion: My project
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-01-11 20:11:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-25 21:55:16
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
// #include<priority_queue>
#include <memory>
using namespace std; 
using namespace std;

class A {
public:
    int i;
    virtual void fun() { }
};

int main(void) {
    //类中有虚函数就会有虚函数表指针的存在，这个指针指向虚函数表开始地址，而每个虚函数表指针指向各自虚函数
    A a;
    int length = 0;
    length = sizeof(a);
    cout << length << endl;

    char *p1 = (char*) & a;
    char *p2 = (char*) & (a.i);

    if (p1 == p2) cout << "虚函数表指针位于对象内存末尾" << endl;
    else cout << "虚函数表指针位于对象内存开始" << endl;

    return 0;
}
