/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-13 15:59:22
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-13 16:44:11
 */
/*
力扣111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。

示例一：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最小深度 2（3->9） 。
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
// 1.递归深搜
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);

        if (!root->left && root->right) return 1 + rightDepth;
        if (root->left && !root->right) return 1 + leftDepth;
        int res =  1 + min(leftDepth, rightDepth);
        return res;
    }
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};
// 精简写法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        if (!root->left && root->right) return 1 + minDepth(root->right);
        if (root->left && !root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->right), minDepth(root->right));
    }
};
// 2.使用广搜进行层序遍历
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            ans++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = que.front();
                que.pop();
                // 当左右孩子都为空的时候，说明是最低点的一层了，直接退出即可
                if (!temp->left && !temp->right) return ans;
                if (temp->left) que.push(temp->left);
                if (temp->right) que.push(temp->right);
            }
        }
        return ans;
    }
};