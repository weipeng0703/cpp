/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-26 09:17:07
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-26 09:54:14
 */
/*
力扣46. 全排列
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

// 注：
// 对于排列问题，结果是跟nums大小一样的排列，所以需要记录回溯树上的所有节点的结果
// 因此，排列问题的回溯树不需要剪枝，因此回溯过程一般不需要index，而要用used数组记录当前该数是否已经用过
// 且每层都是从0开始搜索而不是startIndex

// 1.正常回溯
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }
        // 每层都是从0开始搜索而不是startIndex
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
            // 依次交换元素位置
            swap(nums[i], nums[index]);
            backtrack(nums,index + 1);
            // 回溯
            swap(nums[i], nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) return ans;
        backtrack(nums, 0);
        return ans;
    }
};