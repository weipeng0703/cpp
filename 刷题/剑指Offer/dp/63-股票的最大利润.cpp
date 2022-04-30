/*
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
示例 1:
    输入: [7,1,5,3,6,4]
    输出: 5
    解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
        注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:
    输入: [7,6,4,3,1]
    输出: 0
    解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// 1.用两个状态变量记录当前最小价格与最大利润（动态规划）
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        int min_price = INT_MIN;
        int max_profit = 0;
        for (int ele : prices)
        {
            min_price = min(ele, min_price);
            max_profit = max(max_profit, ele - min_price);
        }
        return max_profit;
    }
};
