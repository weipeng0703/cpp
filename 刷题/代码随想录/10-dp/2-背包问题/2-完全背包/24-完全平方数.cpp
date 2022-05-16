/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-16 18:56:57
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-16 19:25:42
 */
/*
力扣279. 完全平方数
给你一个整数 n ，返回 和为 n 的完全平方数的 最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；
换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
    输入：n = 12
    输出：3 
    解释：12 = 4 + 4 + 4
示例 2：
    输入：n = 13
    输出：2
    解释：13 = 4 + 9
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

// 1. dp-完全背包 先物品后背包
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i * i <= n; i++) {
            for (int j = i; j <= n; j++) {
                if (j - i * i >= 0) {
                    dp[j] = min(dp[j], dp[j - i * i] + 1);
                }
            }
        }
        return dp[n];
    }
};


// 2. dp-完全背包 先背包后物品
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {      // 背包
            for (int j = 1; j * j <= i; j++) {      // 物品
                if (i - j * j >= 0) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
};