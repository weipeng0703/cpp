/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-12 10:56:31
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-16 08:18:42
 */
/*
力扣377. 组合总和 Ⅳ
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。

示例 1：
    输入：nums = [1,2,3], target = 4
    输出：7
    解释：
    所有可能的组合为：
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    请注意，顺序不同的序列被视作不同的组合。
示例 2：
    输入：nums = [9], target = 3
    输出：0
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

// 虽然题目是组合总和，但是顺序不同也是不同的答案，所以本质上是排列问题
// 排列问题，要先遍历背包再遍历元素
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。

// 1. dp-完全背包
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        vector<int> dp(target + 1, 0);      // dp[j]表示凑成目标有几种方式
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
            }
        }
    }
        return dp[target];
    }
};