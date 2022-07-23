/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 09:16:41
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 09:42:14
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
#include<queue>
using namespace std; 
/*
力扣-剑指 Offer 10- II. 青蛙跳台阶问题
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
    输入：n = 2
    输出：2
示例 2：
    输入：n = 7
    输出：21
示例 3：
    输入：n = 0
    输出：1
*/ 

// 1-dp
class Solution {
public:
    int numWays(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
            // 1000000007是一个质数（素数），对质数取余能最大程度避免结果冲突/重复
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};