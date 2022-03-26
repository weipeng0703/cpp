/*
14(1)
给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。返回 可以获得的最大乘积 。
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m-1] 。
请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

14(2)与上题一样，唯一不同在于需要考虑 大数越界情况下的求余问题
给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
每段绳子的长度记为 k[0],k[1]...k[m - 1] 。
请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

示例 1：
    输入: 2
    输出: 1
    解释: 2 = 1 + 1, 1 × 1 = 1
示例 2:
    输入: 10
    输出: 36
    解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
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
using namespace std; 

// 1.动态规划(内存爆炸)
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for (int i = 3; i < dp.size(); i++)
        {
            int curMax = 0;
            for (int j = 1; j < i; j++)
            {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};
// 时间复杂度：O(n)。遍历一遍数组
// 空间复杂度：O(1)。没有用到额外空间

// 2.贪心
class Solution {
public:
    int cuttingRope(int n) {       
        if (n <= 3) return n - 1;
        long ret = 1;
        if (n % 3 == 1){
            ret = 4;
            n = n - 4;
        }
        if (n % 3 == 2){
            ret = 2;
            n = n - 2;
        }
        while (n) {
            // 大数越界情况下的求余问题
            ret = ret * 3 % 1000000007;
            n = n - 3;
        }
        return (int)ret;
    }
};