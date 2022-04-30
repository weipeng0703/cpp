/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-20 10:34:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-20 11:27:55
 */
/*
力扣669. 修剪二叉搜索树
给你二叉搜索树的根节点 root ，同时给定最小边界low 和最大边界 high。
通过修剪二叉搜索树，使得所有节点的值在[low, high]中。
修剪树 不应该 改变保留在树中的元素的相对结构 (即，如果没有被移除，原有的父代子代关系都应当保留)。 
可以证明，存在 唯一的答案 。
所以结果应当返回修剪好的二叉搜索树的新的根节点。注意，根节点可能会根据给定的边界发生改变。

示例 1：
    输入：root = [1,0,2], low = 1, high = 2
    输出：[1,null,2]
示例二：
    输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    输出：[3,2,null,1]
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 1.树中节点符合条件
        if (root == nullptr) return nullptr;
        // 2.对于不符合条件的节点
        // 如果根节点大于high说明root的右子树全部不符合条件，直接在左子树中操作即可
        if (root->val > high) return trimBST(root->left, low, high);
        // 如果根节点小于low说明root的左子树全部不符合条件，直接在右子树中操作即可
        if (root->val < low) return trimBST(root->right, low, high);
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};
