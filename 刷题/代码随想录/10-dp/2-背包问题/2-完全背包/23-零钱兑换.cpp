/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-16 08:10:11
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-16 08:50:05
 */
/*
力扣322. 零钱兑换
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。
（该题与零钱兑换二的区别是——该题求最少硬币个数）

示例 1：
    输入：coins = [1, 2, 5], amount = 11
    输出：3 
    解释：11 = 5 + 5 + 1
示例 2：
    输入：coins = [2], amount = 3
    输出：-1
示例 3：
    输入：coins = [1], amount = 0
    输出：0
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

// 1. dp-完全背包 先遍历物品后遍历背包（组合）
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return 0;
        // 因为是求最小硬币个数，所以无关组合和排列
        // 沿用19题中的遍历顺序，使用组合 先遍历物品后遍历背包
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if (dp[j - coins[i]] != INT_MAX) {  // 说明当前的金额j可以被凑齐
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

// 2. dp-完全背包 先遍历背包后遍历物品（排列）
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) return 0;
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {     // 背包
            for (int j = 0; j < coins.size(); j++) {    // 物品
                if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX) {  
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};