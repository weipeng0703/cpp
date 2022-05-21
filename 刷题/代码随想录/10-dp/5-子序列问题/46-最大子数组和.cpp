/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-21 10:07:19
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-21 10:30:21
 */
/*
力扣53. 最大子数组和
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
子数组 是数组中的一个连续部分。

示例 1：
    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
    输入：nums = [1]
    输出：1
示例 3：
    输入：nums = [5,4,-1,7,8]
    输出：23
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

// 1. 暴力遍历
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MIN;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp = 0;
            for (int j = i; j < nums.size(); j++)   {
                temp += nums[j];
                ans = temp > ans? temp : ans;
            }
        }
        return ans;
    }
};

// 2.贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MIN;      // 记录最终结果
        int temp = 0;           // 记录不为负数的结果
        for (int i = 0; i < nums.size(); i++){
            temp += nums[i];
            if (temp > ans) ans = temp;
            // 如果temp < 0,令他为0，从下一个数字开始重新计算子序和
            if (temp <= 0) temp = 0;
        }
        return ans;
    }
};

// 3. dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        // if (nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};