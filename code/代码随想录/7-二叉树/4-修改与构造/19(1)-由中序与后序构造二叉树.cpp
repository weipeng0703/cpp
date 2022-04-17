/*
 * @Descripttion: 从中序与后序遍历序列构造二叉树
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-17 08:51:34
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-17 10:03:26
 */
/*
力扣106. 从中序与后序遍历序列构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

示例一：
    输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    输出：[3,9,20,null,null,15,7]
示例二：
    输入：inorder = [-1], postorder = [-1]
    输出：[-1]
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
#include<priority_queue>
using namespace std; 

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 树这个结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.递归深搜
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int inHead, int inTail, int postHead, int postTail) {
        if (postHead > postTail) return nullptr;
        int root = postTail;
        int indexRootInorder = index[postorder[root]];      // 中序序列中根节点的位置
        int leftTreeSize = indexRootInorder - inHead;           // 左子树大小
        TreeNode* ans = new TreeNode(postorder[root]);

        ans->left = helper(inorder, postorder, inHead, indexRootInorder - 1, postHead, postHead + leftTreeSize - 1);
        ans->right = helper(inorder, postorder, indexRootInorder + 1, inTail, postHead + leftTreeSize, postTail - 1);
        return ans;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) return nullptr;
        int size = inorder.size();
        for (int i = 0; i < size; i++) index[inorder[i]] = i;
        return helper(inorder, postorder, 0, size - 1, 0, size - 1);
    }
};