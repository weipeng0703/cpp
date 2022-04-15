/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-15 09:04:03
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-15 09:40:14
 */
/*
力扣404. 左叶子之和
给定二叉树的根节点 root ，返回所有左叶子之和。

示例一：
    输入: root = [3,9,20,null,null,15,7] 
    输出: 24 
    解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
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
    // 树这个结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.队列广搜
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = que.front();
                que.pop();
                if (temp->left) {
                    que.push(temp->left);
                    // 通过父节点判断某节点是不是左叶子节点
                    // 而且只需要左边判断即可
                    if (!temp->left->left && !temp->left->right) ans += temp->left->val;
                }
                if (temp->right) que.push(temp->right);
            }
        }
        return ans;
    }
};
// 2.深搜
class Solution {
public:
    void inOrder(TreeNode* root, int& ans) {
        if (root == nullptr) return;
        if (root->left) {
            // 通过父节点判断某节点是不是左叶子节点
            if (!root->left->left && !root->left->right) ans += root->left->val;
            inOrder(root->left, ans);
        }
        if (root->right) inOrder(root->right, ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        inOrder(root, ans);
        return ans;
    }
};