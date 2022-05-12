/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-08 19:06:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-12 10:34:25
 */
/*
力扣518. 零钱兑换 II
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 
题目数据保证结果符合 32 位带符号整数。

示例 1：
    输入：amount = 5, coins = [1, 2, 5]
    输出：4
    解释：有四种方式可以凑成总金额：
        5=5
        5=2+2+1
        5=2+1+1+1
        5=1+1+1+1+1
示例 2：
    输入：amount = 3, coins = [2]
    输出：0
    解释：只用面额 2 的硬币不能凑成总金额 3 。
示例 3：
    输入：amount = 10, coins = [10] 
    输出：1
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

// 注：因为是组合问题，该题一定要先遍历元素再遍历背包，否则会产生重复答案
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
// 1. dp-完全背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (coins.size() == 0) return 0;
        vector<int> dp(amount + 1, 0);      // dp[j]表示凑成目标j元有几种方式
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) dp[j] += dp[j - coins[i]];
        }
        return dp[amount];
    }
};