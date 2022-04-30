/*
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

示例 1:
    输入：[3,9,20,null,null,15,7]
    输出：
[
  [3],
  [9,20],
  [15,7]
]
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
// 利用队列长度将指定数目的节点遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            // temp记录每一层的节点
            vector<int> temp;
            // 根据当前队列大小知道该层的节点数目
            for (int i = que.size(); i > 0; i--)
            // 把size的值最初值赋给i是没问题的，本轮中size改变不会影响i。而将0赋值给i的话第一轮的size变成2了，所以 i<q.size()从i<1变成了i<2; 所以3,9输出在同一行了。这是错误的
            // for第一轮循环的时候先判断初始条件;循环体结束后判断中间的条件，满足时，执行之后的第三条语句
            // for (int i = 0; i < que.size(); i++)
            {
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if (node->left != nullptr) que.push(node->left);
                if (node->right != nullptr) que.push(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};