/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-25 10:35:24
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-25 11:23:02
 */
/*
力扣491. 递增子序列
给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。
数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。

示例 1：
    输入：nums = [4,6,7,7]
    输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
示例 2：
    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]
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

// 1.回溯法加set去重
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, int index) {
        if (temp.size() >= 2) ans.push_back(temp);
        if (index > nums.size()) return;

        unordered_set<int> uset;        // 对本层元素去重
        for (int i = index; i < nums.size(); i++) {
            // 如果 1.temp非空且当前nums[i] < temp里的数(非递增) 或者 2.nums[i]是本层中已经用过的数
            // 跳过
            if ((!temp.empty() && nums[i] < temp.back()) || uset.find(nums[i] != uset.end())) continue;
            uset.insert(nums[i]);      // 记录下这个元素在本层用过了，本层后面不能再用了
            temp.push_back(nums[i]);
            backtrack(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};


// 2.回溯法加数组去重
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, int index) {
        if (temp.size() >= 2) ans.push_back(temp);
        if (index > nums.size()) return;

        vector<int> used(201, 0);        // 对本层元素去重,-100 <= nums[i] <= 100
        for (int i = index; i < nums.size(); i++) {
            // 如果 1.temp非空且当前nums[i] < temp里的数(非递增) 或者 
            // 2.nums[i]是本层中已经用过的数.因为-100 <= nums[i] <= 100，所以判断时要将数字加上100符合正整数条件
            // 跳过
            if ((!temp.empty() && nums[i] < temp.back()) || (used[nums[i] + 100] == 1)) continue;
            used[nums[i] + 100] = 1;      // 记录下这个元素在本层用过了，本层后面不能再用了
            temp.push_back(nums[i]);
            backtrack(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};
