/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-22 10:48:50
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-22 14:21:36
 */
/*
力扣77. 组合
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
你可以按 任何顺序 返回答案。

示例 1：
    输入：n = 4, k = 2
    输出：
        [
        [2,4],
        [3,4],
        [2,3],
        [1,2],
        [1,3],
        [1,4],
        ]
示例 2：
    输入：n = 1, k = 1
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

// 1.无优化的回溯法
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int n, int k, int index) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i <= n; i++) {
            temp.push_back(i);
            backtrack(n, k, i + 1);
            path.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }
};
// 2.回溯法剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int n, int k, int index) {
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        // 剪枝
        // 假设n = 4, k = 3; 放入的路径头只能从1或2开始,[1,2,3] [1,2,4] [2,3,4]
        // 所以剪枝条件可以从最开始的情况就列出来
        for (int i = index; i <= n - (k - path.size()) + 1; i++) {
            temp.push_back(i);
            backtrack(n, k, i + 1);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        return ans;
    }
};