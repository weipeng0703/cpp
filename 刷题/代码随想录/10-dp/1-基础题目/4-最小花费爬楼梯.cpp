/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-06 15:40:20
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-06 16:10:50
 */
/*
力扣746. 使用最小花费爬楼梯
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
一旦你支付此费用，即可选择向上爬一个或者两个台阶。
你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
请你计算并返回达到楼梯顶部的最低花费。

示例 1：
    输入：cost = [10,15,20]
    输出：15
    解释：你将从下标为 1 的台阶开始。
    - 支付 15 ，向上爬两个台阶，到达楼梯顶部。
    总花费为 15 。
示例 2：
    输入：cost = [1,100,1,1,1,100,1,1,100,1]
    输出：6
    解释：你将从下标为 0 的台阶开始。
    - 支付 1 ，向上爬两个台阶，到达下标为 2 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 4 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 6 的台阶。
    - 支付 1 ，向上爬一个台阶，到达下标为 7 的台阶。
    - 支付 1 ，向上爬两个台阶，到达下标为 9 的台阶。
    - 支付 1 ，向上爬一个台阶，到达楼梯顶部。
    总花费为 6 。
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
    int minCostClimbingStairs(vector<int>& cost) {
        // 设置dp数组表示到达某一层的花费
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        // 因为最后一步可能是从前一阶一步走上来的，也可能是从前前一阶走两步上来的，所以取前二者最小值即可
        return min(dp[dp.size() - 1], dp[dp.size() - 2]);
    }
};

// 2. dp压缩空间
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp0 = cost[0];
        int dp1 = cost[1];
        for (int i = 2; i < cost.size(); i++) {
            int sum = min(dp0, dp1) + cost[i];
            dp0 = dp1;
            dp1 = sum;
        }
        // 因为最后一步可能是从前一阶一步走上来的，也可能是从前前一阶走两步上来的，所以取前二者最小值即可
        return min(dp0, dp1);
    }
};