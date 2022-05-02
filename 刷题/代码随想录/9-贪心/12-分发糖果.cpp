/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-02 16:49:09
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-02 19:16:34
 */
/*
力扣135. 分发糖果
n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 
示例 1:
    输入：ratings = [1,0,2]
    输出：5
    解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
示例 2:
    输入：ratings = [1,2,2]
    输出：4
    解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
        第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
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

// 1.两遍遍历
// 两次贪心的策略：
//     一次是从左到右遍历，只比较右边孩子评分比左边大的情况。
//     一次是从右到左遍历，只比较左边孩子评分比右边大的情况。
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;
        vector<int> ans(n, 1);
        // 从左往右遍历一遍
        for (int i = 1; i < n; i++) {
            // 数组ans元素均为1，可以直接++
            if (ratings[i] > ratings[i - 1]) ans[i] = ans[i - 1] + 1;
        }
        // 再从右往左遍历一遍
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                if (ans[i] <= ans[i + 1]) ans[i] = ans[i + 1] + 1;
            }
        }
        return accumulate(ans.begin(), ans.end(), 0);
    }
};