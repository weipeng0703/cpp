/*
给定节点数为 n 的二叉树的前序遍历和中序遍历结果，请重建出该二叉树并返回它的头结点。

示例一：
输入：[1,2,4,7,3,5,6,8],[4,7,2,1,5,3,8,6]
输出：{1,2,3,4,#,5,6,#,7,#,#,8}
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    // 哈希表用于记录中序
    unordered_map<int, int> index;
public:
    TreeNode* helper(vector<int> pre, vector<int> vin, int pre_left, int pre_right, 
                    int vin_left, int vin_right)
    {
        if (pre_left > pre_right)
        {
            return nullptr;
        }
        int root = pre_left;
        // 因为之前main函数中已经构建好关于中序的哈希表了，我们想利用先序遍历中已知第一个数为根节点去找中序遍历中该节点在哪里
        int root_index_inorder = index[pre[root]];
        TreeNode* ans = new TreeNode(vin[root_index_inorder]);
        int size_left_tree = root_index_inorder - vin_left;
        // 递归去求左子树的排序和右子树的排序
        // 先序的左边和中序的左边
        ans->left = helper(pre, vin, pre_left + 1, pre_left + size_left_tree, vin_left, root_index_inorder - 1);
        // 先序的右边和中序的右边
        ans->right = helper(pre, vin, pre_left + 1 + size_left_tree, pre_right, root_index_inorder + 1, vin_right);
        
        return ans;
    }
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.size() == 0 || vin.size() == 0 || pre.size() != vin.size())
        {
            return nullptr;
        }
        // 哈希表记录中序遍历
        for (int i = 0; i < vin.size(); i++)
        {
            index[vin[i]] = i;
        }
        int size = pre.size();
        return helper(pre, vin, 0, size - 1, 0, size - 1);

    }
};

class Solution {
public:
    unordered_map<int, int> index;
    TreeNode* helper(vector<int> preorder, vector<int> inorder, int pre_left, int pre_right, int in_left, int in_right){
        if (pre_left > pre_right)
        {
            return nullptr;
        }
        int rootIndex = pre_left;
        int rootIndexInorder = index[preorder[rootIndex]];
        TreeNode* ans = new TreeNode(inorder[rootIndexInorder]);
        int leftTreeSize = rootIndexInorder - in_left;

        ans->left = helper(preorder, inorder, pre_left + 1, pre_left + leftTreeSize, 
        in_left, rootIndexInorder - 1);
        ans->right = helper(preorder, inorder, pre_left + leftTreeSize + 1, pre_right, 
        rootIndexInorder + 1, in_right);
        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0 || preorder.size() != preorder.size())
        {
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++)
        {
            index[inorder[i]] = i;
        }
        int size = preorder.size();
        return helper(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};