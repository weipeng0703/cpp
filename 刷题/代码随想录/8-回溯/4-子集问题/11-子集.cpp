/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-25 08:58:17
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-25 09:47:54
 */
/*
力扣78. 子集
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
    输入：nums = [1,2,3]
    输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
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

// 以回溯树的角度看，之前的组合问题和分割问题求的是回溯树的叶子节点，
// 而子集问题不光要最后的叶子，也要中间的所有节点，即组合问题要的是回溯树的所有节点

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, int index) {
        // 将下一个数放入集合前，要先将path放入结果
        ans.push_back(temp);
        if (index > nums.size()) return;

        for (int i = index; i < nums.size(); i++) {
            temp.push_back(nums[i]);
            backtrack(nums, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};