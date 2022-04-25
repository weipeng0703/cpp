/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-25 10:05:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-25 11:23:50
 */
/*
力扣90. 子集 II
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：
    输入：nums = [1,2,2]
    输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
示例 2：
    输入：nums = [0]
    输出：[[],[0]]
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

// 该题类似组合问题中的8.组合总和二
// 都是进行树的层级间的去重
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, int index) {
        // 将下一个数放入集合前，要先将path放入结果
        ans.push_back(temp);
        if (index > nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            if (i > index && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            backtrack(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 进行树的层级间去重前，要先将数组排序
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};
