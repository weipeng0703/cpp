/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-18 09:51:11
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-18 10:25:29
 */
/*
力扣98. 验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。
有效 二叉搜索树定义如下：
    节点的左子树只包含 小于 当前节点的数。
    节点的右子树只包含 大于 当前节点的数。
    所有左子树和右子树自身必须也是二叉搜索树。

示例 1：
    输入：root = [2,1,3]
    输出：true
示例 2：
    输入：root = [5,1,4,null,null,3,6]
    输出：false
    解释：根节点的值是 5 ，但是右子节点的值是 4 。
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

// 1. 对于二叉搜索树中序遍历是有序的所以根据中序遍历判断
class Solution {
public:
    vector<int> ans;
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    bool isValidBST(TreeNode* root) {
        inOrder(root, ans);
        for (int i = 0; i < ans.size() - 1; i++) {
            if (ans[i] >= ans[i + 1]) return false;
        }
        return true;
    }
};
// 2.不额外开辟新的空间的中序遍历
class Solution {
public:
    TreeNode* pre = nullptr; // 用来记录前一个节点
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        // 左
        bool left = isValidBST(root->left);
        // 中
        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root; // 记录前一个节点
        // 右
        bool right = isValidBST(root->right);
        return left && right;
    }
};