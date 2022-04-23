/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-23 15:15:25
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-23 16:06:51
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-23 11:28:22
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-23 15:15:06
 */
/*
力扣40. 组合总和 II
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
示例 2：
    输入: candidates = [2,5,2,1,2], target = 5,
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

// 1.去重的回溯法加剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int> vec, int targetSum, int sum, int index) {
        if (sum == targetSum) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i < vec.size() && sum + vec[i] <= targetSum; i++) {
            // 去除回溯树层级间的重复
            if (i > index && vec[i] == vec[i - 1]) continue;
            sum += vec[i];
            temp.push_back(vec[i]);
            backtrack(vec, targetSum, sum, i + 1);
            sum -= vec[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return ans;
        // 为了回溯树层级间的去重和剪枝必须先将数组排序
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return ans;
    }
};