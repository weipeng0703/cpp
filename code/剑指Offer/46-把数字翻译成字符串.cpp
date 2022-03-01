/*
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

示例 1：
    输入: 12258
    输出: 5
    解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
// #include<iomanip>
#include<algorithm>
using namespace std; 

// 1.dp
class Solution {
public:
    int translateNum(int num) {
        string temp = to_string(num);
        int n = temp.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i < dp.size(); i++)
        {
            int first = temp[i - 2] - '0';
            int second = temp[i - 1] - '0';
            if ((first * 10 + second >= 10) && (first * 10 + second <= 25))
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }
        return dp[n];
    }
};
// 方法二：不用转换字符串，直接使用数字
class Solution {
public:
    int translateNum(int num) {
        if (num == 0) return 1;
        return f(num);
    }

    int f(int num) {
        if (num < 10) {
            return 1;
        }
        // 如果该数的余数在[10,25],比如25，可以拆分为2和5，也可以作为25一个整体进行翻译。
        if (num % 100 < 26 && num % 100 > 9) {
            return f(num / 10) + f(num / 100);
        } 
        // 否则不能组合计算，比如56，只能拆分为5和6
        else {
            return f(num / 10);
        }
    }
};