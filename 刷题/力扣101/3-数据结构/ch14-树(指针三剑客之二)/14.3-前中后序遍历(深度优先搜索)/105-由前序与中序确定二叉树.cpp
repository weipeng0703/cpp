/*
给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。

示例一：
    Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    Output: [3,9,20,null,null,15,7]
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
private:
    // 先声明哈希映射
    unordered_map<int, int> index;
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_head, int pre_tail, int in_head, int in_tail)
    {
        if (pre_head > pre_tail)
        {
            return nullptr;
        }
        
        int root = pre_head;
        // 因为之前main函数中已经构建好关于中序的哈希表了，我们想利用先序遍历中已知第一个数为根节点去找中序遍历中该节点在哪里
        int root_index_inorder = index[preorder[root]];
        TreeNode* ans = new TreeNode(preorder[root]);       // new TreeNode(inorder[root_index_inorder也可])
        int size_left_tree = root_index_inorder - in_head;

        // 如下两行确定参数只需要注意：
        // 前序遍历中左子树范围=中序遍历中左子树范围；
        // 前序遍历中右子树范围=中序遍历中右子树范围；
        ans->left = helper(preorder, inorder, pre_head + 1, pre_head + size_left_tree, in_head, root_index_inorder - 1);
        
        ans->right = helper(preorder, inorder, pre_head + 1 + size_left_tree, pre_tail, root_index_inorder + 1, in_tail);

        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return nullptr;
        }
        int size = preorder.size();
        for (int i = 0; i < size; i++)
        {
            index[inorder[i]] = i;
        }
        return helper(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};
