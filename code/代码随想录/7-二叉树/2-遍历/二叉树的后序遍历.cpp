/*
力扣145. 二叉树的后序遍历
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。
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
    void postOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        postOrder(root->left, vec);
        postOrder(root->right, vec);
        vec.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postOrder(root, ans);
        return ans;
    }
};

// 2.迭代
// 先序遍历是中左右，后续遍历是左右中，那么我们只需要调整一下先序遍历的代码顺序，就变成中右左的遍历顺序，
// 然后在反转result数组，输出的结果顺序就是左右中了
// (先序)中左右——>(先序时左子节点先入栈)中右左——>(reverse钟左右的结果序列)左右中
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
            if (temp->left) st.push(temp->left);
            if (temp->right) st.push(temp->right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};