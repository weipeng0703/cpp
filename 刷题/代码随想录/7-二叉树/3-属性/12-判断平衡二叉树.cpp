/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-14 09:35:25
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-14 10:11:28
 */

/*
力扣110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。。
示例一：
    输入：root = [3,9,20,null,null,15,7]
    输出：true
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

// 1.
class Solution {
public:
    // 求树深
    int treeHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        if (abs(treeHeight(root->left) - treeHeight(root->right)) <= 1 
            && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};
// 清楚一些，且不容易出错
class Solution {
public:
    // 求树深
    int treeHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = treeHeight(root->left);
        int rightHeight = treeHeight(root->right);

        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
            return true;
        }
        return false;
    }
};