/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。

示例 1:
    给定二叉树 [3,9,20,null,null,15,7]，
    返回它的最大深度 3 
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        return max(maxDepth(root->left),maxDepth(root->right)) + 1; 
    }
};