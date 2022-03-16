/*
写一个函数，求两个整数之和，要求在函数体内不得使用 “+”、“-”、“*”、“/” 四则运算符号。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    int add(int a, int b) {
        //因为不允许用+号，所以求出异或部分和进位部分依然不能用+ 号，所以只能循环到没有进位为止        
        while(b != 0)
        {
        //保存进位值，下次循环用
            int c = (unsigned int)(a & b) << 1;//C++中负数不支持左移位，因为结果是不定的
        //保存不进位值，下次循环用，
            a ^= b;
        //如果还有进位，再循环，如果没有，则直接输出没有进位部分即可。
            b = c;   
        }
        return a;
    }
};