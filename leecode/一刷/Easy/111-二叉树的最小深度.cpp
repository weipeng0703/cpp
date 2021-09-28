/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明：叶子节点是指没有子节点的节点。
*/
#include<algorithm>
#define INT_MAX 24666666
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1.深度优先搜索
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        else if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }
        
        int min_depth = INT_MAX;
        
        if (root->left != nullptr)
        {
            min_depth = min(minDepth(root->left), min_depth);
        }
        if (root->right != nullptr)
        {
            min_depth = min(minDepth(root->right), min_depth);
        }
        return min_depth + 1;
        
    }
};