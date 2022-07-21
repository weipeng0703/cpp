/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-21 09:52:21
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-21 10:51:42
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

/*
力扣T-22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
    输入：n = 3
    输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：
    输入：n = 1
    输出：["()"]
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1-dfs
class Solution {
public:
    vector<string> ans;
    void dfs(const string& str, int left, int right) {
        if (left == 0 && right == 0) {
            ans.push_back(str);
            return;
        }
        if (left > 0) dfs(str + '(', left - 1, right);
        if (left < right) dfs(str + ')', left, right - 1);
        return;
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;
        dfs("", n, n);
        return ans;
    }
};
// 2-回溯
class Solution {
public:
    vector<string> ans;
    string temp = "";
    void backtrack(int l, int r, int n, string& str) {
        if (l == n && r == n) ans.push_back(temp);
        // l<r表示右边括号先进了，错误
        if (l > n || r > n || l < r) return;
        str += '(';
        backtrack(l + 1, r, n, str);
        str.pop_back();
        str += ')';
        backtrack(l, r + 1, n, str);
        str.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        if (n == 0) return ans;
        backtrack(0, 0, n, temp);
        return ans;
    }
};