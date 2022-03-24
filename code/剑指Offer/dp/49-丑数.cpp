/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。

示例 1：
    输入：n = 10
    输出：12
    解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
示例 2：
    输入：n = 1
    输出：1
    解释：1 通常被视为丑数。
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
    int nthUglyNumber(int n) {
        vector<int> ans(n + 1);
        ans[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i <= n; i++)
        {
            int num2 = ans[p2] * 2, num3 = ans[p3]  * 3, num5 = ans[p5] * 5;
            ans[i] = min(min(num2, num3), num5);
            if (ans[i] == num2)
            {
                ++p2;
            }
            if (ans[i] == num3)
            {
                ++p3;
            }
            if (ans[i] == num5)
            {
                ++p5;
            }
        }
        return ans[n];
    }
};
// 2.暴力
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v;
        for (long long a = 1; a <= INT_MAX; a = a * 2)
            for (long long b = a; b <= INT_MAX; b=b * 3)
                for (long long c = b; c <= INT_MAX; c = c * 5)
                    v.push_back(c);
        sort(v.begin(), v.end());
        return v[n - 1];
    }
};
// 3.优先队列的小顶堆
// 利用优先队列有自动排序的功能
// 每次取出队头元素，存入队头元素*2、队头元素*3、队头元素*5
// 但注意，像 12 这个元素，可由 4 乘 3 得到，也可由 6 乘 2 得到，所以要注意去重
class Solution {
public:
    int nthUglyNumber(int n) {
        // priority_queue <序列中元素类型, 序列, 比较法则>
        priority_queue <double, vector<double>, greater<double>> q;
        double answer = 1;
        for (int i = 1; i < n; ++i)
        {
            q.push(answer * 2);
            q.push(answer * 3);
            q.push(answer * 5);
            answer = q.top();
            q.pop();
            while (!q.empty() && answer == q.top())
                q.pop();
        }
        return answer;
    }
};