/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/
#include<algorithm>
#include<math.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    int high(TreeNode* root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return max(high(root->left), high(root->right)) + 1;

    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        return isBalanced(root->left) && isBalanced(root->right) && abs(high(root->left) - high(root->right)) <= 1;
        
    }
};