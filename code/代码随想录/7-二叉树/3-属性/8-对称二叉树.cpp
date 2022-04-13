/*
力扣101. 对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例一：
    输入：root = [1,2,2,3,4,4,3]
    输出：true
示例二：
    输入：root = [1,2,2,null,3,null,3]
    输出：false
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
    bool equal(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        else if (!left && right) return false;
        else if (left && !right) return false;
        else if (left->val != right->val) return false;
        return equal(left->left, right->right) && equal(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return equal(root->left, root->right);
    }
};
// 2.非递归(使用队列 栈 vector均可)
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        if (root->left && !root->right) return false;
        if (!root->left && root->right) return false;
        queue<TreeNode* node> que;
        que.push(root->left);
        que.push(root->right);

        // 本质跟递归相同，还是比较左子树和右子树 && 左子树左节点和右子树右节点 && 左子树右节点和右子树左节点
        while (!que.empty()) {
            TreeNode* left = que.front(); que.pop();
            TreeNode* right = que.front(); que.pop();

            if (!left && !right) continue;
            if (!left || !right || left->val != right->val) return false;

            que.push(left->left);
            que.push(right->right);
            que.push(left->right);
            que.push(right->left);
        }
        return true;
    }
};