/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-01 10:23:44
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-19 22:54:08
 */
/*
力扣T-450. 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。
返回二叉搜索树（有可能被更新）的根节点的引用。
一般来说，删除节点可分为两个步骤：
    首先找到需要删除的节点；
    如果找到了，删除它。

示例1：
    输入：root = [5,3,6,2,4,null,7], key = 3
    输出：[5,4,6,2,null,null,7]
    解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
    一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
    另一个正确答案是 [5,2,6,null,4,null,7]。
示例 2:
    输入: root = [5,3,6,2,4,null,7], key = 0
    输出: [5,3,6,2,4,null,7]
    解释: 二叉树不包含值为 0 的节点
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

// 1-五种情况
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return root;
        if (root->val == key) {
            // 情况1-该节点是叶子节点
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }
            // 情况2-该节点没有右孩子
            else if (root->left && !root->right) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // 情况3-该节点没有左孩子
            else if (!root->left && root->right) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            // 情况4-该节点有左右孩子
            // 将该节点的左孩子节点 接到 该节点右孩子节点的最左孩子节点的左边
            else if (root->left && root->right) {
                TreeNode* cur = root->right;
                while (cur->left) cur = cur->left;
                cur->left = root->left;
                TreeNode* node = root->right;
                delete root;
                return node;
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
            TreeNode* node = root->right;
            // 1.不断将要删除的节点向右子树的最左下方移动
            while (node->left) node = node->left;
            swap(root->val, node->val);
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};


