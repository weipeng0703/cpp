/*
力扣15.三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
示例 2：
    输入：nums = []
    输出：[]
示例 3：
    输入：nums = [0]
    输出：[]
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