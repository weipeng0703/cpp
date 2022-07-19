/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-03 09:33:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-18 22:15:21
 */
/*
力扣-53. 最大子数组和
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

// 1-暴力(有些样例超时)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum > ans) ans = sum;
            }
        }
        return ans;
    }
}; 

// 2-dp
// dp[i]的定义：包括下标i之前的最大连续子序列和为dp[i]。
// 那么我们要找最大的连续子序列，就应该找每一个以为nums[i]为终点的连续最大子序列。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = nums[0];
        vector<int> dp(nums.size(), INT_MIN);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// 3-贪心
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = INT_MIN;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            if (temp > ans) ans = temp;
            if (temp <= 0) temp = 0;
        }
        return ans;
    }
}; 

4-分治