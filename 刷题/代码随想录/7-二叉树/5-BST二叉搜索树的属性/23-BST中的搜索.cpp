/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-18 08:54:59
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-18 09:48:49
 */
/*
力扣700. 二叉搜索树中的搜索
给定二叉搜索树（BST）的根节点 root 和一个整数值 val。
你需要在 BST 中找到节点值等于 val 的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 null 。

示例 1：
    输入：root = [4,2,7,1,3], val = 2
    输出：[2,1,3]
示例 2：
    输入：root = [4,2,7,1,3], val = 5
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
// 注：对于二叉搜索树的遍历，一定要利用其性质（左小右大），代码会简洁很多
// 1. 递归
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        if (root->val < val) return searchBST(root->right, val);
        return nullptr;
    }
};
// 2.迭代
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) return root;
        while (root) {
            if (root->val > val) root = root->left;
            else if (root->val < val) root = root->right;
            else return root;
        }
        return nullptr;
    }
};
