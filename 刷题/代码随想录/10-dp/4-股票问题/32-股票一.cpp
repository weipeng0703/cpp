/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-18 09:08:28
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-18 11:07:09
 */
/*
力扣121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：
    输入：[7,1,5,3,6,4]
    输出：5
    解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
示例 2：
    输入：prices = [7,6,4,3,1]
    输出：0
    解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
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

// 1.暴力(数据太大会超时)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN;
        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        if (ans > 0) return ans;
        else return 0;
    }
};

// 2.贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minNum = INT_MAX;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            minNum = min(prices[i], minNum);    // 取当前区间内的最小值
            ans = max(ans, prices[i] - minNum); // 直接取最大区间的利润
        }
        return ans;
    }
};

// 3.dp
// dp[i][j],i表示天数，
// j取0/1分别表示第i天持有股票/不持有股票拥有的钱
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] -= prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++) {
            // -prices[i]是因为该题中只能各买卖一次股票，所以买入时手中的钱只能是这样
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // dp[i - 1][0] + prices[i]表示卖出手中股票时,之前状态中手里持有股票时的钱数+当前股票价格(用于卖出当前股票)
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }
};