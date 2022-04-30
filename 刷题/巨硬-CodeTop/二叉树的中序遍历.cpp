/*
力扣T94-二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 1.递归
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
// 2.非递归
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root == nullptr)
        {
            return ret;
        }
        stack<TreeNode*> st;

        while (root != nullptr || !st.empty())
        {
            // 一路按照左子节点入栈
            while (root != nullptr)
            {
                st.push_back(root);
                root = root->left;
            }
            // 从最左下的节点开始出栈，一步步回退
            root = st.top();
            st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return ret;
    }
};