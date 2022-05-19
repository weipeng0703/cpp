/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-19 09:33:46
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-19 10:25:44
 */
/*
力扣121. 买卖股票的最佳时机
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

122. 买卖股票的最佳时机 II (股票可以无限次买入卖出)
给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。

123. 买卖股票的最佳时机 III (股票最多买入卖出两次)
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

188. 买卖股票的最佳时机 IV (股票三的泛化——股票最多买入卖出K次)
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

309. 最佳买卖股票时机含冷冻期
给定一个整数数组prices，其中第 prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
    输入: prices = [1,2,3,0,2]
    输出: 3 
    解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
示例 2:
    输入: prices = [1]
    输出: 0
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

// 状态一：买入股票状态（1）今天恰好买入股票（2）之前就买入了股票然后没有操作
// 卖出股票状态，这里就有两种卖出股票状态
// 状态二：今天保持卖出股票状态:(1)之前一天是卖股票的状态即状态三(2)之前一天是冷冻期即状态四
// 状态三：正好是今天卖出股票
// 状态四：今天为冷冻期状态，但冷冻期状态不可持续，只有一天！(其其一天状态只能是状态三)
// j的状态为：
    // 0：状态一
    // 1：状态二
    // 2：状态三
    // 3：状态四

// 1.dp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < prices.size(); i++) {
            // 1.买入股票：(1)保持买入的状态(2)当天买入
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3], dp[i - 1][1]) - prices[i]);
            // 2.卖出股票情况1:保持卖出的状态
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            // 3.卖出股票情况2:当天卖出
            dp[i][2] = dp[i - 1][0] + prices[i];
            // 4.冷冻期
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[prices.size() - 1][3], max(dp[prices.size() - 1][1], dp[prices.size() - 1][2]));
    }
};