/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 19:28:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-11 22:27:52
 */
/*
力扣T-69. x 的平方根 
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
    输入：x = 4
    输出：2
示例 2：
    输入：x = 8
    输出：2
    解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
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

// 1-二分查找
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long) mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else r = mid - 1;
        }
        return ans;
    }
};
// 2-利用指数和对数的结合
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        long long ans = exp(0.5 * log(x));
        return (ans + 1) * (ans + 1) <= x? ans + 1 : ans;
    }
};

