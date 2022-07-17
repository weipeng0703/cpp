/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 09:17:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-16 20:07:16
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
#include<memory>
#include <time.h>
#include<unordered_map>
#include<queue>
using namespace std;

#include <iostream>
using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;
struct A {
    A(){
        cout << "construct: " << ++g_constructCount << endl;    
    }
    
    A(const A& a) {
        cout << "copy construct: " << ++g_copyConstructCount << endl;
    }
    ~A() {
        cout << "destruct: " << ++g_destructCount << endl;
    }
};

A GetA() {
    return A();
}

int main() {
    A a = GetA();
    return 0;
}