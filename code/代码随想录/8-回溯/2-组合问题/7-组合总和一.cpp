/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-23 11:28:22
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-23 15:15:06
 */
/*
力扣39 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
对于给定的输入，保证和为 target 的不同组合数少于 150 个。

示例 1：
    输入：candidates = [2,3,6,7], target = 7
    输出：[[2,2,3],[7]]
    解释：
    2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
    7 也是一个候选， 7 = 7 。
    仅有这两种组合。
示例 2：
    输入: candidates = [2,3,5], target = 8
    输出: [[2,2,2,2],[2,3,3],[3,5]]
示例 3：
    输入: candidates = [2], target = 1
    输出: []
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

// 1.回溯法
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    // 对于组合问题：
    // 如果是一个集合来求组合的话，就需要startIndex，例如：2.组合 ，4.组合总和III
    // 如果是多个集合取组合，各个集合之间相互不影响，那么就不用startIndex，例如：本题和5.电话号码的字母组合
    void backtrack(vector<int> vec, int targetSum, int sum, int index) {
        if (sum > targetSum) return;
        if (sum == targetSum) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < vec.size(); i++) {
            sum += vec[i];
            temp.push_back(vec[i]);
            // 不需要i+1，因为可以取相同的数
            backtrack(vec, targetSum, sum, i);
            sum -= vec[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ans;
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};

// 2.回溯法加剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int> vec, int targetSum, int sum, int index) {
        if (sum == targetSum) {
            ans.push_back(temp);
            return;
        }
        // 因为数组是有序数组，所以当前不满足条件的以后肯定更不可能满足条件
        for (int i = index; i < vec.size() && sum + vec[i] <= targetSum; i++) {
            sum += vec[i];
            temp.push_back(vec[i]);
            backtrack(vec, targetSum, sum, i);
            sum -= vec[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ans;
        // 将数组先排序
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};