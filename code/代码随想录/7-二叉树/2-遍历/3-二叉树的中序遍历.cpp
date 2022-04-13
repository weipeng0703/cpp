/*
力扣94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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
    void inOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        inOrder(root->left, vec);
        vec.push_back(root->val);
        inOrder(root->right, vec);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inOrder(root, ans);
        return ans;
    }
};

// 2.迭代
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr) return ans;
        stack<TreeNode*> st;
        TreeNode* temp = root;
        // 指针用来遍历节点
        while (temp != nullptr || !st.empty()) {
            // 依次将左边的节点放入栈中
            if (temp != nullptr) {
                st.push(temp);
                temp = temp->left;
            } else {
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);
                temp = temp->right;
            }
        }
        return ans;
    }
};