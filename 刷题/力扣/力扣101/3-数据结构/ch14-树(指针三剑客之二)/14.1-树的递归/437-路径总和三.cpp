/*
给定一个二叉树的根节点 root ，和一个整数 targetSum ，
求该二叉树里节点值之和等于 targetSum 的 路径 的数目。

路径 不需要从根节点开始，也不需要在叶子节点结束，
但是路径方向必须是向下的（只能从父节点到子节点）。

示例一：
    输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    输出：3
    解释：和等于 8 的路径有 3 条，5->3, 5->2->1, -3->11。
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
// 1.递归深度优先搜索
class Solution {
public:
    int find_sum(TreeNode* root, int tar)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int ret = 0;
        if (root->val == tar)
        {
            ret++;
        }
        ret += find_sum(root->left, tar - root->val);
        ret += find_sum(root->right, tar - root->val);
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        // 下面两部分是针对头节点的
        if (root == nullptr)
        {
            return 0;
        }
        int ans = find_sum(root, targetSum);
        // 下面是针对头节点的两个子节点的，注意他们要用的是pathSum而不是find_sum。因为也需要判断他们是否为空
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};

// 2.前缀和法
