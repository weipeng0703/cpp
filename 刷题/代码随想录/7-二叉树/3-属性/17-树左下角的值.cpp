/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-15 09:41:20
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-15 10:12:40
 */
/*
力扣513. 找树左下角的值
给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
假设二叉树中至少有一个节点。

示例一：
    输入: root = [2,1,3]
    输出: 1
示例二:
    输入: [1,2,3,4,null,5,6,null,null,7]
    输出: 7
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
// 1.队列广搜
// 广搜后取队列最后一位元素的队首元素即为树最后一层的最左边元素
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            vector<int> temp;
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front();
                que.pop();
                temp.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            ans.push_back(temp);
        }
        return ans[ans.size() - 1][0];
    }
};
// 2.深搜
class Solution {
public:
    int maxLength = INT_MIN;
    int maxLeftVal = 0;
    void travel(TreeNode* root, int leftLen) {
        if (!root->left && !root->right) {
            if (leftLen > maxLength) {
                maxLength = leftLen;
                maxLeftVal = root->val;
            }
        }
        if (root->left) {
            leftLen++;
            travel(root->left, leftLen);
            leftLen--;
        }
        if (root->right) {
            leftLen++;
            travel(root->right, leftLen);
            leftLen--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        travel(root, 0);
        return maxLeftVal;
    }
};