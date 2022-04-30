/*
 * @Descripttion: 从前序与中序遍历序列构造二叉树
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-17 09:04:31
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-17 10:03:17
 */
/*
力扣105. 从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
示例一：
    输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
    输出: [3,9,20,null,null,15,7]
示例二：
    输入: preorder = [-1], inorder = [-1]
    输出: [-1]
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
// 1.
class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int pre_head, int pre_tail, int in_head, int in_tail)
    {
        if (pre_head > pre_tail) return nullptr;
        int root = pre_head;
        // 因为之前main函数中已经构建好关于中序的哈希表了，我们想利用先序遍历中已知第一个数为根节点去找中序遍历中该节点在哪里
        int root_index_inorder = index[preorder[root]];     // 中序序列中头节点所在的位置
        TreeNode* ans = new TreeNode(preorder[root]);       // 以头节点构造新树
        int size_left_tree = root_index_inorder - in_head;  // 树的左子树大小为中序中根节点位置-中序开头的位置

        ans->left = helper(preorder, inorder, pre_head + 1, pre_head + size_left_tree, in_head, root_index_inorder - 1);
        
        ans->right = helper(preorder, inorder, pre_head + 1 + size_left_tree, pre_tail, root_index_inorder + 1, in_tail);

        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        int size = preorder.size();
        for (int i = 0; i < size; i++) index[inorder[i]] = i;
        return helper(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};


class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int preHead, int preTail, int inHead, int inTail) {
        if (preHead > preTail) return nullptr;
        int root = preHead;     // 先序序列中头节点的位置
        int indexRootInorder = index[preorder[root]];    // 根据先序序列中头结点的位置->头节点元素值->中序序列中头节点位置
        TreeNode* ans = new TreeNode(preorder[root]);
        int leftTreeSize = indexRootInorder - inHead;

        ans->left = helper(preorder, inorder, preHead + 1, preHead + leftTreeSize, inHead, indexRootInorder - 1);
        ans->right = helper(preorder, inorder, preHead + leftTreeSize + 1, preTail, indexRootInorder + 1, inTail);
        return ans;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return nullptr;
        int size = preorder.size();
        // 将中序序列中的节点存入哈希表中，方便之后查找
        for (int i = 0; i < size; i++) index[inorder[i]] = i;
        return helper(preorder, inorder, 0, size - 1, 0, size - 1);
    }
};
