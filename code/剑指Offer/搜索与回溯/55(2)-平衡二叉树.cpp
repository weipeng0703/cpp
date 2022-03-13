/*
输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。。

示例一：
给定二叉树 [3,9,20,null,null,15,7]
    3
   / \
  9  20
    /  \
   15   7
输出:True

示例 2:
给定二叉树 [1,2,2,3,3,null,null,4,4]

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
返回 false 

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
// 自上而下的递归，会产生大量重复的计算
class Solution {
public:
    int depth(TreeNode* root){
        if (root == nullptr)
        {
            return 0;
        }
        return max(depth(root->left), depth(root->right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr){
            return true;
        }
        else{
            return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
// 时间复杂度：
// O(NlogN)： 最差情况下（为 “满二叉树” 时）， 
// isBalanced(root) 遍历树所有节点，判断每个节点的深度 depth(root) 需要遍历 各子树的所有节点 。
// 总体时间复杂度 = 每层执行复杂度 * 层数复杂度 = O(n) * O(logN)
// 空间复杂度 O(N)： 
// 最差情况下（树退化为链表时），系统递归需要使用 O(N) 的栈空间

// 自下而上的递归
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } 
        else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
    }
};
// 时间复杂度 O(N)： N 为树的节点数；最差情况下，需要递归遍历树的所有节点。
// 空间复杂度 O(N)： 最差情况下（树退化为链表时），系统递归需要使用 O(N) 的栈空间。