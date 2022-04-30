/*
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）

示例 1：
    输入：k = 2, prices = [2,4,1]
    输出：2
    解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，
    这笔交易所能获得利润 = 4-2 = 2 。
示例 2：
    输入：k = 2, prices = [3,2,6,5,0,3]
    输出：7
    解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 
        这笔交易所能获得利润 = 6-2 = 4 。
        随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 
        这笔交易所能获得利润 = 3-0 = 3 。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 
class Solution {
public:
    int profitUnlimited(vector<int>& prices)
    {
        int n = prices.size();
        int profit = 0;
        for (int i = 0; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int size = prices.size();
        if (size < 2)
        {
            return 0;
        }
        if (k >= size / 2)
        {
            return profitUnlimited(prices);
        }
        vector<int> buy(size + 1, INT_MIN), sell(size + 1, 0);
        for (int i = 0; i < size; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                // 买入的最大收益
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                // 卖出的最大收益
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
