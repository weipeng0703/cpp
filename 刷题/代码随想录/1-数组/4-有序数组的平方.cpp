/*
力扣977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1：
    输入：nums = [-4,-1,0,3,10]
    输出：[0,1,9,16,100]
    解释：平方后，数组变为 [16,1,0,9,100]
    排序后，数组变为 [0,1,9,16,100]
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
// 1.暴力
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0)
        {
            return ans;
        }
        for (auto& ele : nums)
        {
            ele = ele * ele;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};
// 时间复杂度：O(n) + O(nlogn) = O(nlogn)
// 空间复杂度：O(1)

// 2.双指针
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int last = nums.size() - 1;
        for (int left = 0, right = nums.size() - 1; left <= right; )
        {
            if (nums[left] * nums[left] < nums[right] * nums[right])
            {
                ans[last] = nums[right] * nums[right];
                --right;
                --last;
            }
            else if (nums[left] * nums[left] >= nums[right] * nums[right])
            {
                ans[last] = nums[left] * nums[left];
                ++left;
                --last;
            }
        }
        return ans;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)