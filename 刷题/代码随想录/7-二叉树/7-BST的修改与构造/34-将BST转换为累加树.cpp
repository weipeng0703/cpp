/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-21 09:55:57
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-21 11:46:21
 */
/*
力扣538. 把二叉搜索树转换为累加树
给出二叉 搜索 树的根节点，该树的节点值各不相同，请你将其转换为累加树（Greater Sum Tree），
使每个节点 node 的新值等于原树中大于或等于 node.val 的值之和。

提醒一下，二叉搜索树满足下列约束条件：
节点的左子树仅包含键 小于 节点键的节点。
节点的右子树仅包含键 大于 节点键的节点。
左右子树也必须是二叉搜索树。

示例 1：
    输入：[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    输出：[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]
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
// 思路：BST的中序遍历是左中右的有序递增数列啊！将其倒过来 右中左 遍历，便可以将原树中从最大的节点往前递加到最小节点
// 定义一个变量num记录需要加到下一个节点上的数，遍历到某个节点时，
// 1.他的val等于之前自己的val加上记录的num
// 2.num变为当前加和完的val

// 1.反中序遍历(右中左)递归
class Solution {
public:
    int num = 0;        // 存放累加量
    void helper(TreeNode* root) {
        if (root == nullptr) return;
        helper(root->right);        // 右
        // 中
        root->val += num;       //  当前节点的val = 原val + 暂存的num
        num = root->val;        // num = 加和完后的val（包含所有>=当前jiedianval的节点val之和）
        helper(root->left);         // 左
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};

// 2.反中序遍历(右中左)迭代
class Solution {
public:
    int num = 0;        // 存放累加量
    void helper(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->right;
            } else {
                cur = st.top();
                st.pop();
                cur->val += num;
                num = cur->val;
                cur = cur->left;
            }
        }
    }
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return;
        helper(root);
        return root;
    }
};

