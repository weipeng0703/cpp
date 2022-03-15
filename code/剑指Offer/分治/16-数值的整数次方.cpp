/*
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，x的n次方）。不得使用库函数，同时不需要考虑大数问题。

示例 1：
    输入：x = 2.00000, n = 10
    输出：1024.00000
示例 2：
    输入：x = 2.10000, n = 3
    输出：9.26100
示例 3：
    输入：x = 2.00000, n = -2
    输出：0.25000
    解释：2-2 = 1/22 = 1/4 = 0.25
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

// 快速幂递归
// 快速幂递归+两处优化(左右移与位运算)
class Solution {
public:
    double temp(double x, long long n){
        if (n == 0)
        {
            return 1.00;
        }
        // 右移一位代表除以2
        double y = temp(x, n >> 1);
        // 位运算判断奇偶数
        return n & 1 == 1? y * y * x : y * y;
        }
    double myPow(double x, int n) {
        long long N = n;
        return N >= 0? temp(x, N) : 1.0 / temp(x, -N);
    }
};