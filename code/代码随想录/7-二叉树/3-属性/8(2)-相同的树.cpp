/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-15 08:39:12
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-15 09:01:02
 */
/*
力扣100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
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
// 1.递归深搜
class Solution {
public:
    bool equal(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        else if (p && !q) return false;
        else if (!p && q) return false;
        else if (p->val != q->val) return false;
        return equal(p->left, q->left) && equal(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return equal(p, q);
    }
};
