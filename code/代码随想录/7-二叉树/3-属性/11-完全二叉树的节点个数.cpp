/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-14 08:57:12
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-14 09:33:39
 */
/*
力扣222. 完全二叉树的节点个数
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。
完全二叉树 的定义如下：
在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。
示例一：
输入：root = [1,2,3,4,5,6]
输出：6
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
// 1.(通用)深搜统计序列size
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ans) {
        if (root == nullptr) return;
        ans.push_back(root->val);
        inOrder(root->left, ans);
        inOrder(root->right, ans);
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> ans;
        inOrder(root, ans);
        return ans.size();
    }
};

class Solution {
public:
    int inOrder(TreeNode* root) {
        if (root == nullptr) 0;
        int left = inOrder(root->left);
        int right = inOrder(root->right);
        return 1 + left + right;
    }
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return inOrder(root);
    }
};


// 2.(通用)广搜统计序列size
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<int> ans;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            ans.push_back(temp->val);
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
        return ans.size();
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> que;
        que.push(root);
        int count = 0;
        while (!que.empty()) {
            TreeNode* temp = que.front();
            que.pop();
            ++count;
            if (temp->left) que.push(temp->left);
            if (temp->right) que.push(temp->right);
        }
        return count;
    }
};
// 3.(针对完全二叉树)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        TreeNode* leftNode = root->left;
        TreeNode* rightNode = root->right;
        int leftHeight = 0;
        int rightHeight = 0;
        // 分别统计左右树高
        while (leftNode) {
            leftHeight++;
            leftNode = leftNode->left;
        }
        while (rightNode) {
            rightHeight++;
            rightNode = rightNode->right;
        }
        // 如果左右子树同样高，使用完全二叉树节点公式
        if (leftHeight == rightHeight) return (2 << leftHeight) - 1;
        // 不一样高，递归求左右子树节点
        else return countNodes(root->left) + countNodes(root->right) + 1;
    }
};