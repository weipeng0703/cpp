/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-19 09:02:12
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-31 21:13:50
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
力扣235. BST的最近公共祖先
给定一个BST, 找到该树中两个指定节点的最近公共祖先。
最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。
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
// 1.使用树的通用解法
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        if (!left && right) return right;
        if (left && !right) return left;
        return nullptr;
    }
};

// 2.利用BST的性质(BST有序（相当于自带方向），可以从上向下遍历)
// 因为树是二分搜索树，所以若根节点有子树，比它小的所有节点都在其左边，比它大的节点都在其右边
// 所以对于p和q，如果二者的最大值小于根节点，那么他们一定在左子树中，他们的的公共祖先也一定在左半子树中
// 所以对于p和q，如果二者的最小值大于根节点，那么他们一定在右子树中，他们的的公共祖先也一定在右半子树中
// 对于其他所有情况（一个数大于根节点，一个树小于根节点，二者一定分别在根节点两侧），那么最近公共祖先一定是根节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (max(p->val, q->val) < root->val) return lowestCommonAncestor(root->left, p, q);
        if (min(p->val, q->val) > root->val) return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};