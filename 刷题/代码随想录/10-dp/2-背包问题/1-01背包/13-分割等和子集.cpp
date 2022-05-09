/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-08 19:06:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-09 10:45:49
 */
/*
力扣416. 分割等和子集
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：
    输入：nums = [1,2,3,5]
    输出：false
    解释：数组不能分割成两个元素和相等的子集。
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

// 问题转化：本题思路为能否从数组中找出和为sum/2的元素数组(价值为sum / 2的背包)
// 背包重量:sum / 2
// 背包要放入的物品重量与物品价值相同，都是nums[i]
// 背包如果正好装满，证明找到了总和为sum / 2的元素子集
// 背包中每一个物品都不能重复放入

// 1. dp(01背包问题)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        if (nums.size() == 1) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        // 如果nums元素总和不能平分，一定没有分割方式
        if (sum % 2 == 1) return false;
        int target = sum / 2;       // 目标价值
        // 题目中说每个元素 <= 100, 元素个数 <= 200，所以元素总和最大为20000.其一半最多为10000
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++){
            for (int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[target] == target) return true;
        return false;
    }
};
