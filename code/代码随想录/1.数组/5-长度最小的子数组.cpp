/*
力扣209.长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。

示例 1：
    输入：target = 7, nums = [2,3,1,2,4,3]
    输出：2
    解释：子数组 [4,3] 是该条件下的长度最小的子数组。
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
// 1.滑动窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int ans = INT_MAX;
        int i = 0, j = 0;
        int sum = 0;
        while (j < nums.size())
        {
            sum += nums[j];
            while (sum >= target)
            {
                ans = min(ans, j - i + 1);
                // 精髓：sum减去滑动窗口最左边的数字，往右移
                sum -= nums[i];
                ++i;
            }
            ++j;
        }
        return ans == INT_MAX? 0 : ans;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)