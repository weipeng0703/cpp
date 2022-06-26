/*
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// 1.递归
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
        return isBalanced(root->left) && isBalanced(root->right) 
                && abs(high(root->left) - high(root->right)) <= 1;
        
    }
};