/*
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

示例 1:
    输入: 1
    输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:
    输入: 2
    输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]
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

// 1.动态规划
class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<int>> dp(15, vector<int>(70, 0));
        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        // dp[i][j]表示投i个骰子时出现点数j的次数
        for (int i = 2; i <= n; i++)
        {
        // 因为投n个骰子最少的点数是n个骰子均为1，所以j从等于i开始
        for (int j = i; j <= 6 * i; j++)
        {
            // 因为从第n-1个骰子到第n个骰子，中间差的点数个数只可能为1~6
            for (int k = 1; k <= 6; k++)
            {
                if (j - k <= 0)
                {
                    break;
                }
                dp[i][j] += dp[i - 1][j - k];
            }
        }
        }
        // 计算完出现某个点数的次数，即可使用 频率/总次数 的方式求概率
        int all = pow(6, n);
        // 求投n个筛子点数的概率
        vector<double> ans;
        for (int i = n; i <= 6 * n; i++)
        {
            ans.push_back(dp[n][j] * 1.0 / all);
        }
        return ans;
    }
};