/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-03 15:21:25
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-03 16:03:50
 */
/*
力扣T-46. 全排列
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
    输入：nums = [1,2,3]
    输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：
    输入：nums = [0,1]
    输出：[[0,1],[1,0]]
示例 3：
    输入：nums = [1]
    输出：[[1]]
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1-回溯法
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack (vector<int>& nums, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used);
            temp.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ans;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return ans;
    }
};

// 2.交换回溯
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++) {
            swap(nums[i], nums[index]);
            backtrack(nums,index + 1);
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ans;
        backtrack(nums, 0);
        return ans;
    }
};