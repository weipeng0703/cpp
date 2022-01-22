/*
给定一棵二叉树，你需要计算它的直径长度。
一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。

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
// 1.深度搜索（递归做遍历）
class Solution {
public:
    int ans;

    int maxDepth(TreeNode* root)        // 求该节点深度（从该节点到叶子共有几个节点 ）
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        ans = ans(left + right, maxd);      // 直径为根节点左右子树深度之和
        return max(left, right) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        maxDepth(root);
        return ans;
    }
};