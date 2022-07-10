/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 20:15:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 20:38:38
 */
/*
力扣T-129. 求根节点到叶节点数字之和
给你一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
每条从根节点到叶节点的路径都代表一个数字：
例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
计算从根节点到叶节点生成的 所有数字之和 。
叶节点 是指没有子节点的节点。

示例1：
    输入：root = [1,2,3]
    输出：25
    解释：
    从根到叶子节点路径 1->2 代表数字 12
    从根到叶子节点路径 1->3 代表数字 13
    因此，数字总和 = 12 + 13 = 25
示例 2：
    输入：root = [4,9,0,5,1]
    输出：1026
    解释：
    从根到叶子节点路径 4->9->5 代表数字 495
    从根到叶子节点路径 4->9->1 代表数字 491
    从根到叶子节点路径 4->0 代表数字 40
    因此，数字总和 = 495 + 491 + 40 = 1026
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1.回溯
class Solution {
public:
    int ans = 0;
    vector<int> path;
    // 求当前路径上数字的和
    int vectorSum (vector<int> path) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++) sum = sum * 10 + path[i];
        return sum;
    }
    void backtrack(TreeNode* root) {
        if (!root->left && !root->right) {
            ans += vectorSum(path);
            return;
        }
        if (root->left) {
            path.push_back(root->left->val);
            backtrack(root->left);
            path.pop_back();
        }
        if (root->right) {
            path.push_back(root->right->val);
            backtrack(root->right);
            path.pop_back();
        }
        return;
    }

    int sumNumbers(TreeNode* root) {
        if (root == nullptr) return 0;
        path.push_back(root->val);
        backtrack(root);
        return ans;
    }
};