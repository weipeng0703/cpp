/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-22 21:41:47
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-22 22:02:12
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
力扣T-110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。
本题中，一棵高度平衡二叉树定义为：
一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：true
示例 2：
    输入：root = [1,2,2,3,3,null,null,4,4]
    输出：false
示例 3：
    输入：root = []
    输出：true
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

// 1-求树的节点高度后判断
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root->left), height(root->left));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->left)) {
            return true;
        }
        return false;
    }
};
