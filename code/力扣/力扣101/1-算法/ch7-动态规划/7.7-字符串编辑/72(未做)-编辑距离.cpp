/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。
如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。

示例 1：
    输入：coins = [1, 2, 5], amount = 11
    输出：3 
    解释：11 = 5 + 5 + 1
示例 2：
    输入：coins = [2], amount = 3
    输出：-1
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.DP
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount == 0)
        {
            return -1;
        }
        int n = coins.size();
        // 注意：dp大小设置为amount + 1，
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (const int& coin : coins)
            {
                if (coin <= i)
                {
                    // 在还没有将该coin放入背包前背包里已经有i - coin了，
                    // 此时满足条件的数组中有dp[i - coin]个数，
                    // 加入coin后代表dp[i - coin]又多了一个数
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};