/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-14 10:13:08
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-14 11:07:25
 */
/*
力扣257. 二叉树的所有路径
给你一个二叉树的根节点 root ，按 任意顺序 ，返回所有从根节点到叶子节点的路径。
叶子节点 是指没有子节点的节点。
示例一：
    输入：root = [1,2,3,null,5]
    输出：["1->2->5","1->3"]
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 树这个结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.深搜加回溯
class Solution {
public:
    void travel(TreeNode* root, vector<int>& path, vector<string>& ans) {
        path.push_back(root->val);
        // 如果该节点是叶子节点
        if (!root->left && !root->right) {
            string temp;
            // 将路径转换为字符串
            // i < path.size() - 1;是为了后面只将root节点放入路径，不用再多加->
            for (int i = 0; i < path.size() - 1; i++) {
                temp += to_string(path[i]);
                temp += "->";
            }
            temp += to_string(root->val);
            ans.push_back(temp);
        }
        if (root->left) {
            travel(root->left, path, ans);
            path.pop_back();
        }
        if (root->right) {
            travel(root->right, path, ans);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        if (root == nullptr) return ans;
        travel(root, path, ans);
        return ans;
    }
};