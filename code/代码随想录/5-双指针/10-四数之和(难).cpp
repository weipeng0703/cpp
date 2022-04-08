/*
力扣18. 四数之和（同样的思路可以解决 K数之和问题）
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 
[nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：
0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。

示例 1：
    输入：nums = [1,0,-1,0,-2,2], target = 0
    输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：
    输入：nums = [2,2,2,2,2], target = 8
    输出：[[2,2,2,2]]
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

// 1.双指针解法+剪枝
// 固定nums[i]与nums[k]，使用双指针求解剩余的两数之和
// 可以将时间复杂度由n的四次方降为n的三次方
// 但是一定要注意判断条件时的写法，如果直接把四个数相加容易产生溢出
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() == 0) return ans;
        sort(nums.begin(), nums.end());

        // 固定第一个数
        for (int k = 0; k < nums.size(); k++)
        {
            // 对第一个数字的重复数剪枝（从后往前剪）
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            // 固定第二个数
            for (int i = k + 1; i < nums.size(); i++)
            {
                // 对第二个数字的重复数剪枝
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;
                // 双指针
                int left = i + 1, right = nums.size() - 1;
                while (left < right)
                {
                    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!注意!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if (nums[k] + nums[i] > target - (nums[left] + nums[right])) {
                        --right;
                        // 剪枝
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } else if (nums[k] + nums[i] < target - (nums[left] + nums[right])) {
                        ++left;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                    } else {
                        ans.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1]) --right;
                        while (left < right && nums[left] == nums[left + 1]) ++left;
                        --right;
                        ++left;
                    }
                }
            }
        }
        return ans;
    }
};