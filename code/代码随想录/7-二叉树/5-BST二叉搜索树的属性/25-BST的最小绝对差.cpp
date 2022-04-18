/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-18 10:27:31
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-18 10:55:16
 */
/*
力扣530. 二叉搜索树的最小绝对差
给你一个二叉搜索树的根节点 root ，返回 树中任意两不同节点值之间的最小差值 。
差值是一个正数，其数值等于两值之差的绝对值。

示例 1：
    输入：root = [4,2,6,1,3]
    输出：1
示例 2：
    输入：root = [1,0,48,null,null,12,49]
    输出：1
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

Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    // 树这个结构体的构造函数
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 1. 对于二叉搜索树中序遍历是有序的所以根据中序遍历判断
class Solution {
public:
    vector<int> ans;
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrder(root, ans);
        int res = INT_MAX;
        for (int i = 1; i < ans.size(); i++) {
            res = min(res, ans[i] - ans[i - 1]);
        }
        return res;
    }
};
// 2.不额外开辟新的空间的中序遍历
class Solution {
private:
    int result = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) {
        if (cur == nullptr) return;
        traversal(cur->left);   // 左
        if (pre != nullptr){       // 中
            result = min(result, cur->val - pre->val);
        }
        pre = cur; // 记录前一个
        traversal(cur->right);  // 右
}
public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};