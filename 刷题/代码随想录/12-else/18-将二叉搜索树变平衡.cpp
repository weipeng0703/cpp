/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-01 20:11:44
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-01 20:32:14
 */
/*
力扣1382. 将二叉搜索树变平衡
给你一棵二叉搜索树，请你返回一棵 平衡后 的二叉搜索树，新生成的树应该与原来的树有着相同的节点值。
如果有多种构造方法，请你返回任意一种。
如果一棵二叉搜索树中，每个节点的两棵子树高度差不超过 1 ，我们就称这棵二叉搜索树是 平衡的 。

示例 1：
    输入：root = [1,null,2,null,3,null,4,null,null]
    输出：[2,1,3,null,null,null,4]
    解释：这不是唯一的正确答案，[3,1,4,null,2,null,null] 也是一个可行的构造方案。
示例 2：
    输入: root = [2,1,3]
    输出: [2,1,3]
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.中序遍历将原树转化为有序数组，然后根据有序数组构造二叉搜索树
class Solution {
public:
    vector<int> temp;
    // 中序遍历
    void travel(TreeNode* root) {
        if (root == nullptr) return;
        travel(root->left);
        temp.push_back(root->val);
        travel(root->right);
    }
    // 根据有序数组构造二叉搜索树
    TreeNode* getBST(vector<int>& vec, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = getBST(vec, left, mid - 1);
        node->right = getBST(vec, mid + 1, right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        if (root == nullptr) return nullptr;
        travel(root);
        return getBST(temp, 0, temp.size() - 1);
    }
};