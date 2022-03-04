/*
请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。

示例 1:
    输入：root = [1,2,2,3,4,4,3]
    输出：true
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 递归比较
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 如果是空树
        if(!root)
            return true;
        else
            return recurrent(root->left, root->right);
    }
    // 此函数比较二叉树中位置对称的两个节点
    bool recurrent(TreeNode* left, TreeNode* right){
        // 结束条件1：如果对称两个节点都为空，则返回true
        if(!left && !right){
            return true;
        }
        // 结束条件2：如果单独一个节点为空，另一个节点不为空，又或者是对称节点间的val值不等，则返回false
        if(!left || !right || left->val != right->val)
            return false;
        // 该层符合对称二叉树的要求，开始比较下一层
        return recurrent(left->left, right->right) && recurrent(left->right, right->left);      
    }
};
// 时间复杂度O(N) ：其中 N 为二叉树的节点数量，每次执行 recur() 可以判断一对节点是否对称，因此最多调用 N/2 次 recur() 方法。
// 空间复杂度 O(N)：最差情况下二叉树退化为链表，系统使用 O(N) 大小的栈空间。

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 求树的镜像，两树对比
class Solution {
public:
    // 判断两树是否相同
    bool isContainer(TreeNode* A, TreeNode* B)
    {
        if(A == nullptr && B == nullptr)
        {
            return true;
        }
        else if(A == nullptr || B == nullptr || A->val != B->val)
        {
            return false;
        }
        return isContainer(A->left, B->right) && isContainer(A->right, B->left);
    }
    // 求树的镜像
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorTree(root->left);
        mirrorTree(root->right);
        return root;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
        {
            return true;
        }
        TreeNode* tempTree = mirrorTree(root);
        return isContainer(root, tempTree);
    }
};