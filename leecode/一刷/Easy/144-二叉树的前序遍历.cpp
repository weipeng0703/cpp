/*
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
*/
#include<vector>
using namespace std;

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
    void preorder(TreeNode* root, vector<int> v)
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