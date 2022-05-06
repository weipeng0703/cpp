/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-05 14:33:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-06 15:16:18
 */
/*
力扣509. 斐波那契数
斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。
该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
F(0) = 0，F(1) = 1
F(n) = F(n - 1) + F(n - 2)，其中 n > 1

示例 1:
    输入：n = 2
    输出：1
    解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例 2:
    输入：n = 2
    输出：1
    解释：F(2) = F(1) + F(0) = 1 + 0 = 1
示例三：
    输入：n = 4
    输出：3
    解释：F(4) = F(3) + F(2) = 2 + 1 = 3
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
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1. dp
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// 2. dp压缩空间
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int d1 = 1;
        int d2 = 2;
        for (int i = 3; i < n + 1; i++){
            int sum = d1 + d2;
            d1 = d2;
            d2 = sum;
        }
        return d2;
    }
};