/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-13 09:25:57
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-13 10:12:52
 */
/*
力扣226. 翻转二叉树
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

示例一：
    输入：root = [4,2,7,1,3,6,9]
    输出：[4,7,2,9,6,3,1]
示例二：
    输入：root = [2,1,3]
    输出：[2,3,1]
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

Definition for a binary tree node.
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        swap(root->left, root->right);      // 中
        invertTree(root->left);     // 左
        invertTree(root->right);    // 右
        return root;
    }
};
// 2.广搜
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                // 将该节点的左右孩子先反转再放入队列
                // 这样即可将每一层的孩子翻转
                swap(temp->left, temp->right);
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
};