/*
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例一：
    输入：root = [1,2,2,3,4,4,3]
    输出：true
示例二：
    输入：root = [1,2,2,null,3,null,3]
    输出：false
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
    bool is_equal(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        else if ((left == nullptr && right != nullptr) || (right == nullptr && left != nullptr))
        {
            return false;
        }
        else if (left->val != right->val)
        {
            return false;
        }
        return is_equal(left->left, right->right) && is_equal(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root){
        if (root == nullptr)
        {
            return true;
        }
        return is_equal(root->left, root->right);
    } 
};