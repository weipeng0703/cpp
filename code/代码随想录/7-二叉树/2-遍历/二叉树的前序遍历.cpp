/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-12 09:50:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-12 10:33:18
 */
/*
力扣144. 二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.递归
class Solution {
public:
    void PreOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        PreOrder(root->left, vec);
        PreOrder(root->right, vec);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        PreOrder(root, ans);
        return ans;
    }
};

// 2.迭代(借助栈)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            // 右节点先入栈，才能做到出栈时右节点后出栈
            if (temp->right) st.push(temp->right);
            if (temp->left) st.push(temp->left);
        }
        return ans;
    }
};
// 3.迭代另一种写法
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            // 先将栈头元素保存
            ans.push_back(st.top()->val);
            TreeNode* temp = st.top();
            st.pop();
            // 右节点先入栈，才能做到出栈时右节点后出栈
            if (temp->right) st.push(temp->right);
            if (temp->left) st.push(temp->left);
        }
        return ans;
    }
};