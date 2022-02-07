/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例一：
    输入：root = [1,null,2,3]
    输出：[1,2,3]
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
    void preorder(TreeNode* root, vector<int> &v)
    {
        if (root == nullptr)
        {
            return; 
        }
        v.push_back(root->val);
        preorder(root->left, v);
        preorder(root->right, v);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
// 2.迭代（非递归方式）
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        stack<TreeNode*> temp;
        temp.push(root);
        while (!temp.empty())
        {
            TreeNode* node = temp.top();
            res.push_back(node->val);
            temp.pop();
            // 注意：栈式先进后出，所以要先访问左子树要先把左子树后放入
            if (node->right != nullptr)
            {
                stack.push(node->right);
            }
            if (node->left != nullptr)
            {
                stack.push(node->left);
            }
        }
        return res;
    }
};