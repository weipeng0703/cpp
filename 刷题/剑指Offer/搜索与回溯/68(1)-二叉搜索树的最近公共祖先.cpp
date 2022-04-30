/*
给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

示例 1:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
    输出: 6 
    解释: 节点 2 和节点 8 的最近公共祖先是 6。
示例 2:
    输入: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
    输出: 2
    解释: 节点 2 和节点 4 的最近公共祖先是 2, 因为根据定义最近公共祖先节点可以为节点本身。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 二叉树通用解法
// 递归
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (!left && right)
        {
            return right;
        }
        else if (left && !right)
        {
            return left;
        }
        // 这一个条件一定要加上，要不然若一个节点左右均搜索不到p和q，会返回root（即该节点），这样就完全错误了
        else if (!right && !left)
        {
            return nullptr;
        }
        // p与q分别在两侧，中间节点即为所求
        return root;
    }
};

// 利用二叉搜索树的性质
// 因为树是二分搜索树，所以若根节点有子树，比它小的所有节点都在其左边，比它大的节点都在其右边
// 所以对于p和q，如果二者的最大值小于根节点，那么他们一定在左子树中，他们的的公共祖先也一定在左半子树中
// 所以对于p和q，如果二者的最小值大于根节点，那么他们一定在右子树中，他们的的公共祖先也一定在右半子树中
// 对于其他所有情况（一个数大于根节点，一个树小于根节点，二者一定分别在根节点两侧），那么最近公共祖先一定是根节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (max(p->val, q->val) < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (min(p->val, q->val) > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};