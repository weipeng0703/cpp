/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-31 21:17:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-31 21:19:38
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
力扣-1676
本题输入了一个二叉树节点的数组，让你求多个节点的最近公共祖先。
*/ 

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
// 思路：求最近公共祖先->自底向上查找->回溯法->后序遍历（左右中）
// 1.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, vector<TreeNode*> &nodes) {
        if (root == nullptr) return root;
        for (auto node : nodes) {
            if (root == node) return node;
        }
        
        
        
    }
};