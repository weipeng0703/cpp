/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-12 22:26:59
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-12 22:29:59
 */
/*
力扣-39. 组合总和
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
你可以按 任意顺序 返回这些组合。
candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
对于给定的输入，保证和为 target 的不同组合数少于 150 个。

40. 组合总和 II
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。 

示例 1：
    输入: candidates = [10,1,2,7,6,1,5], target = 8,
    输出:
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
示例 2:
    输入: candidates = [2,5,2,1,2], target = 5,
    输出:
    [
    [1,2,2],
    [5]
    ]
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

// 1-回溯+剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& vec, int targetSum, int sum, int index) {
        if (sum > targetSum) return;
        if (sum == targetSum) ans.push_back(temp);
        for (int i = index; i < vec.size() && sum + vec[i] <= targetSum; i++) {
            // 如果该数字与之前数字相同，那么在回溯前一个数字的过程中该数已经用过了
            if (i > index && vec[i] == vec[i - 1]) continue;
            sum += vec[i];
            temp.push_back(vec[i]);
            backtrack(vec, targetSum, sum, i + 1);
            temp.pop_back();
            sum -= vec[i];
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ans;
        // 为了回溯时的剪枝一定要做排序
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};