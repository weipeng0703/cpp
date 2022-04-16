/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-16 11:07:39
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-16 11:30:23
 */
/*
力扣113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。

示例一：
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    输出：[[5,4,11,2],[5,8,4,5]]

示例二:
    输入：root = [1,2,3], targetSum = 5
    输出：[]
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

// 该题注意事项
// 递归函数什么时候需要返回值？什么时候不需要返回值？总结如下三点：

// 1.如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（该题情况）
// 2.如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。（LC236. 二叉树的最近公共祖先
// 3.如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（LC112.路径总和）

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 树这个结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.深搜回溯
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void dfs(TreeNode* root, vector<vector<int>>& ans, int sum) {
        if (!root->left && !root->right && sum == 0) ans.push_back(temp);
        if (!root->left && !root->right) return;

        if (root->left) {
            temp.push_back(root->left->val);
            sum -= root->left->val;
            dfs(root->left, ans, sum);  // 递归
            sum += root->left->val;     // 回溯
            temp.pop_back();            // 回溯
        }
        if (root->right) {
            temp.push_back(root->right->val);
            sum -= root->right->val;
            dfs(root->right, ans, sum); // 递归
            sum += root->right->val;    // 回溯
            temp.pop_back();            // 回溯
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ans;
        temp.push_back(root->val);
        dfs(root, ans, targetSum - root->val);
        return ans;
    }
};