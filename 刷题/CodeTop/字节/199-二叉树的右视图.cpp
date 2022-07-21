/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-21 11:21:34
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-21 15:52:12
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

/*
力扣T199-二叉树的右视图
给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
注——该题解法也适用于求左视图，bfs的话只需要把每一层第一个节点放入结果，dfs前序遍历中左右即可

示例 1：
    输入: [1,2,3,null,5,null,4]
    输出: [1,3,4]
示例 2:
    输入: [1,null,3]
    输出: [1,3]
示例 3:
    输入: []
    输出: []
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1-暴力层次遍历取每一层的最后一个数
class Solution {
public:
    vector<int> ans;
    vector<vector<int>> temp;
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            temp.push_back(vec);
        }
        for (int i = 0; i < temp.size(); i++) ans.push_back(temp[i].back());
        return ans;
    }
};
// 2-bfs,在层序遍历每一层时直接将最后一个节点放入结果数组
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> vec;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                if (i == size - 1) ans.push_back(node->val);
            }
        }
        return ans;
    }
};
// 3-dfs(中右左遍历)每层遍历到的第一个节点就是该层最右边的节点
class Solution {
public:
    void helper(TreeNode* root, vector<int>& res, int level) {
        if (!root) return;
        if (level == res.size()) res.push_back(root->val);
        helper(root->right, res, level+1);
        helper(root->left, res, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, res, 0);
        return res;
    }
};