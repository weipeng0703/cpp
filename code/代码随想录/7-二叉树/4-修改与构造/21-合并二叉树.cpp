/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-17 11:22:11
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-17 15:45:57
 */
/*
力扣617. 合并二叉树
给你两棵二叉树： root1 和 root2 。
想象一下，当你将其中一棵覆盖到另一棵之上时，两棵树上的一些节点将会重叠（而另一些不会）。
你需要将这两棵树合并成一棵新二叉树。
合并的规则是：如果两个节点重叠，那么将这两个节点的值相加作为合并后节点的新值；
             否则，不为 null 的节点将直接作为新二叉树的节点。
返回合并后的二叉树。
注意: 合并过程必须从两个树的根节点开始。

示例 1：
    输入：root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
    输出：[3,4,5,5,4,null,7]
示例 2：
    输入：root1 = [1], root2 = [1,2]
    输出：[2,2]
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
// 1.直接递归
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && !root2) return root1;
        if (!root1 && root2) return root2;
        if (!root1 && !root2) return nullptr;
        TreeNode* ans = new TreeNode(-1);
        ans->val = root1->val + root2->val;     // 中

        ans->left = mergeTrees(root1->left, root2->left);       // 左
        ans->right = mergeTrees(root1->right, root2->right);    // 右
        return ans;
    }
};

// 2.迭代（层序遍历）
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 && !root2) return root1;
        if (!root1 && root2) return root2;
        if (!root1 && !root2) return nullptr;
        queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1->val += node2->val;
            if (node1->left && node2->left) {
                que.push(node1->left);
                que.push(node2->left);
            }
            if (node1->right && node2->right) {
                que.push(node1->right);
                que.push(node2->right);
            }
            if (!node1->left && node2->left) {
                node1->left = node2->left;
            }
            if (!node1->right && node2->right) {
                node1->right = node2->right;
            }
        }
        return root1;
    }
};