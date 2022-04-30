/*
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。

示例 1:
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    输出：[[5,4,11,2],[5,8,4,5]]
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 深搜
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode* root, int target){
        if (root == nullptr)
        {
            return; 
        }
        path.push_back(root->val);
        target -= root->val;
        // 节点为叶节点且从根节点到该节点路径之和为target
        if (root->left == nullptr && root->right == nullptr && target == 0)
        {
            res.push_back(path);
        }
        dfs(root->left, target);
        dfs(root->right, target);
        // 将当前遍历的节点删除
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return res;
    }
};