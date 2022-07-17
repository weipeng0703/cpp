/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-17 22:12:20
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-17 23:10:12
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

力扣-216. 组合总和 III
找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

示例 1：
    输入: k = 3, n = 7
    输出: [[1,2,4]]
    解释:
    1 + 2 + 4 = 7
    没有其他符合的组合了。
示例 2:
    输入: k = 3, n = 9
    输出: [[1,2,6], [1,3,5], [2,3,4]]
    解释:
    1 + 2 + 6 = 9
    1 + 3 + 5 = 9
    2 + 3 + 4 = 9
    没有其他符合的组合了。
示例 3:
    输入: k = 4, n = 1
    输出: []
    解释: 不存在有效的组合。
    在[1,9]范围内使用4个不同的数字，我们可以得到的最小和是1+2+3+4 = 10，因为10 > 1，没有有效的组合。
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

// 只不过是将数组nums改为1到9的确定性数组而已

// 1-回溯
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int k, int targetSum, int sum, int index) {
        if (sum > targetSum) return;
        if (sum == targetSum && temp.size() == k) ans.push_back(temp);
        for (int i = index; i <= 9; i++) {
            sum += i;
            temp.push_back(i);
            backtrack(k, targetSum, sum, i + 1);
            temp.pop_back();
            sum -= i;
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n == 0) return ans;
        // 为了回溯时的剪枝一定要做排序
        backtrack(k, n, 0, 1);
        return ans;
    }
};

// 2-回溯+剪枝
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int k, int targetSum, int sum, int index) {
        if (sum > targetSum) return;
        if (sum == targetSum && temp.size() == k) ans.push_back(temp);
        // 剪枝可以这样去理解：假如k = 3
        // 则从第一次的选择开始：index = 0 时去判断i的范围:i <= 9 - (3 - 0) + 1 = 7
        // 因为1-7总有>=3的数还能去选择：如1-9, 2-9, 3-9, ...... ,789
        // 但是从8开始只剩下89, 从9开始只剩下9，不够选三个数的
        for (int i = index; i <= 9 - (k - temp.size()) + 1; i++) {
            sum += i;
            temp.push_back(i);
            backtrack(k, targetSum, sum, i + 1);
            temp.pop_back();
            sum -= i;
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if (k == 0 || n == 0) return ans;
        backtrack(k, n, 0, 1);
        return ans;
    }
};
