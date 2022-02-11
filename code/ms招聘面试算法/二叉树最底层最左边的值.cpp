/*
力扣剑指 Offer II 045. 二叉树最底层最左边的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。
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
// 广搜
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }
        queue<TreeNode*> q;
        int res = 0;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            // 对每一层进行遍历
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                // 注意队列没有top()，队首是.front()
                // TreeNode* node = q.top();
                q.pop();
                // 利用队列先进先出的性质，第一个进入队列的必然是当前层最左边的节点
                // 因此其也是第一个出队的节点
                if (i == 0)
                {
                    res = node->val;
                }
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};