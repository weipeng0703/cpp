/*
从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

示例 1:
    输入：[3,9,20,null,null,15,7]
    输出：[3,9,20,15,7]
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
// 题目即为考察BFS广度遍历
class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (que.size() != 0)
        {
            TreeNode* temp = que.front();
            que.pop();
            res.push_back(temp->val);
            if (temp->left != nullptr)
            {
                que.push(temp->left);
            }
            if (temp->right != nullptr)
            {
                que.push(temp->right);
        }
    }
    return res;
    }
};