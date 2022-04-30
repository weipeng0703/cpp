/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-22 14:20:02
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-22 15:00:16
 */
/*
力扣216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
1.只使用数字1到9
2.每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1：
    输入: k = 3, n = 7
    输出: [[1,2,4]]
    解释:
    1 + 2 + 4 = 7
    没有其他符合的组合了。
示例 2：
    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]
    解释:
    1 + 2 + 6 = 9
    1 + 3 + 5 = 9
    2 + 3 + 4 = 9
    没有其他符合的组合了。
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
    void backtrack(int targetSum, int k, int sum, int index) {
        if (targetSum == sum && temp.size() == k) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i <= 9; i++){
            sum += i;
            temp.push_back(i);
            backtrack(targetSum, k, sum, i + 1);
            // sum与temp元素个数均需要回溯
            sum -= i;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k > n) return ans;
        backtrack(n, k, 0, 1);
        return ans;
    }
};

// 2.回溯加剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int targetSum, int k, int sum, int index) {
        // 剪枝操作
        if (sum > targetSum) return;
        if (temp.size() == k && sum == targetSum) {
            ans.push_back(temp);
            return;
        }
        for (int i = index; i <= 9 -(k - temp.size()) + 1; i++){
            sum += i;
            temp.push_back(i);
            backtrack(targetSum, k, sum, i + 1);
            // sum与temp元素个数均需要回溯
            sum -= i;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k > n) return ans;
        backtrack(n, k, 0, 1);
        return ans;
    }
};