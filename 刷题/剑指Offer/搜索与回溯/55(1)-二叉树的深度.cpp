/*
输入一棵二叉树的根节点，求该树的深度。
从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。

给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
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
// 1.递归深搜
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// 2.广搜（层序遍历）
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        int count = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            for (int i = que.size(); i > 0; i--)
            {
                TreeNode* temp = que.front();
                que.pop();
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            // 遍历完该层的所有结点之后，count才++；
            count++;
        }
        return count;
    }
};