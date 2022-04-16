/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-16 10:34:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-16 11:06:40
 */
/*
力扣112. 路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。

示例一：
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    输出：true
    解释：等于目标和的根节点到叶节点路径如上图所示。
示例二:
    输入：root = [1,2,3], targetSum = 5
    输出：false
    解释：树中存在两条根节点到叶子节点的路径：
    (1 --> 2): 和为 3
    (1 --> 3): 和为 4
    不存在 sum = 5 的根节点到叶子节点的路径。
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

// 该题注意事项
// 递归函数什么时候需要返回值？什么时候不需要返回值？总结如下三点：

// 1.如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。（LC113.路径总和ii）
// 2.如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。（LC236. 二叉树的最近公共祖先
// 3.如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。（本题的情况）

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
// 1.深搜（精简写法）
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        else if (!root->left && !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};
// 2.深搜（完整写法）
class Solution {
public:
    bool travel(TreeNode* root, int sum) {
        if (!root->left && !root->right && sum == 0) return true;
        if (!root->left && !root->right) return false;

        if (root->left) {
            sum -= root->left->val;
            if (travel(root->left, sum)) return true;
            sum += root->left->val;
        }
        if (root->right) {
            sum -= root->right->val;
            if (travel(root->right, sum)) return true;
            sum += root->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return false;
        return travel(root, targetSum - root->val);
    }
};