/*
给定一个二叉查找树和两个整数 L 和 R，且 L < R，试修剪此二叉查找树，使得修剪后所有
节点的值都在 [L, R] 的范围内。

示例一：
    输入：root = [3,0,4,null,2,null,null,1], low = 1, high = 3
    输出：[3,2,null,1]
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (root == nullptr)
        {
            return nullptr;
        }
        else if (root->val > high)
        {
            return trimBST(root->left, low, high);
        }
        else if (root->val < L)
        {
            return trimBST(root->right, low, high);
        }
        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        return root;
    }
};