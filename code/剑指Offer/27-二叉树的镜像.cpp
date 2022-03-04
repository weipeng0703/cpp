/*
反向层次遍历
请完成一个函数，输入一个二叉树，该函数输出它的镜像。

示例 1:
    输入：root = [4,2,7,1,3,6,9]
    输出：[4,7,2,9,6,3,1]
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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 1.递归
class Solution {
public:
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
};
// 2.迭代（反向层序遍历）
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            TreeNode* temp = que.front();
            que.pop();
            if (temp->left != nullptr)
            {
                que.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                que.push(temp->right);
            }
            TreeNode* temp_1 = temp->left;
            temp->left = temp->right;
            temp->right = temp_1;
        }
        return root;
    }
};
