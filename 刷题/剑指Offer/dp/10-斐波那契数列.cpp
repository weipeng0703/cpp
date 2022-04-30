/*

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
// 1.递归（效率非常低）
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0)
            return 0;
        else if(n == 1)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
// 2.记录中间数据
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> ans = {0,1};
        if (n < 2)
        {
            return ans[n];
        }
        int Fib_1 = 1;
        int Fib_0 = 0;
        int Fib_N = 0;
        for (int i = 2; i <= n; i++)
        {
            Fib_N = Fib_0 + Fib_1;
            Fib_1 = Fib_N;
            Fib_0 = Fib_1;
        }
        return Fib_N;
    }
};
// 单纯动态规划
class Solution {
public:
    int fib(int n) {
        if(n <= 1){
            return n;
        }
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
            dp[i] %= 1000000007;
        }
        return dp[n];
    }
};

// 3.动态规划 + 滚动数组
class Solution {
public:
    int fib(int n) {
        int MOD = 1000000007;
        if (n < 2)
        {
            return n;
        }
        int p = 0, q = 0, r = 1;
        for (int i = 2; i <= n; i++)
        {
            p = q;
            q = r;
            r = (p + q) % MOD;
        }
        return r;
    }
};

