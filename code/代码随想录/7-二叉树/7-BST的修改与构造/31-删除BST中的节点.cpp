/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-20 09:01:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-20 10:12:11
 */
/*
力扣450. 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
    首先找到需要删除的节点；
    如果找到了，删除它。

示例 1：
    输入：root = [5,3,6,2,4,null,7], key = 3
    输出：[5,4,6,2,null,null,7]
    解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
    一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
    另一个正确答案是 [5,2,6,null,4,null,7]。
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
// 1.BST的递归解法
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1.树中没有该节点
        if (root == nullptr) return nullptr;
        // 2.树中有该节点
        if (root->val == key) {
            // 2.1 该节点没有孩子节点
            if (!root->left && !root->right) return nullptr;
            // 2.2 该节点有左孩子没有右孩子
            if (root->left && !root->right) return root->left;
            // 2.3 该节点m没有左孩子有右孩子
            if (!root->left && root->right) return root->right;
            // 2.4 该节点有左右孩子
            if (root->left && root->right) {
                // 寻找root右孩子的最左子孩子节点
                TreeNode* node = root->right;
                while (node->left) node = node->left;
                // 将root左孩子节点接到node左孩子上
                node->left = root->left;
                root = root->right;
            }
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
};
// 2.普通二叉树的删除节点
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // 1.树中没有该节点
        if (root == nullptr) return nullptr;
        // 2.树中有该节点
        if (root->val == key) {
            // 2.递归到最后返回空节点
            if (!root->right) return root->left;
            // 1.不断将要删除的节点向右子树的最左下方移动
            TreeNode* node = root->right;
            while (node->left) node = node->left;
            swap(root->val, node->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};


