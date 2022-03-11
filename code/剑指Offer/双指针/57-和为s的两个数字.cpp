/*
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。
如果有多对数字的和等于s，则输出任意一对即可。

示例：
    输入：nums = [2,7,11,15], target = 9
    输出：[2,7] 或者 [7,2]
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
#include<unordered_map>
#include<algorithm>
using namespace std; 
// 1.暴力遍历会超时
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0)
        {
            return res;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    res.push_back(nums[i]);
                    res.push_back(nums[j]);
                }
                
            }
            
        }
        return res;
    }
};
// 2.双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0)
        {
            return res;
        }
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] + nums[right] == target)
                {
                    res.push_back(nums[left]);
                    res.push_back(nums[right]);
                    break;
                }
            else if (nums[left] + nums[right] > target)
                {
                    --right;
                }
            else
            {
                ++left;
            }
            
        }
        return res;
    }
};