/*
给定一棵二叉搜索树，请找出其中第 k 大的节点的值。
示例 1:
    输入: root = [3,1,4,null,2], k = 1
     3
    / \
   1   4
   \
    2
    输出: 4
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
// 直接进行中序遍历获得有序数列求第K大节点即可
class Solution {
public:
    vector<int> ans;
    void dfs(TreeNode* root){
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }

    int kthLargest(TreeNode* root, int k) {
        if (root == nullptr)
        {
            return -1;
        }
        dfs(root);
        return ans[ans.size() - k];
    }
};