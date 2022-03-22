/*
写一个函数 StrToInt，实现把字符串转换成整数这个功能。不能使用 atoi 或者其他类似的库函数。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
using namespace std; 
// 1.利用字符流 
class Solution {
public:
    int cuttingRope(string str) {
        int ans = 0;
        stringstream ss(str);
        ss >> ans;
        return ans;
    }
};

// 2.常规按顺序求解
// 注意的几点：
// 1.开头越过空格
// 2.将数据表示为 正负位*数据位 的形式
// 3.注意数字大小是否越界
class Solution {
public:
    int cuttingRope(string s) {
        // flag用于记录数据正负
        int res = 0, flag = 1, i = 0, n = s.length();
        // 寻找非空格字符
        while (s[i] == ' '){
            ++i;
        }
        // 判断正负
        if (i < n && (s[i] == '+' || s[i] == '-')){
            flag = (s[i] == '+'? 1 : -1);
            ++i;
        }
        // 处理数字
        for (; i < n; i++){
            if (s[i] >= '0' && s[i] <= '9'){
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && (s[i] - '0' > 7)){
                    return (flag + 1 == 0)? INT_MIN : INT_MAX;
                }
                res = res * 10 + (s[i] - '0');
            }
            // 其他字符
            else{
                break;
            }
        }
        return res * flag;
    }
};