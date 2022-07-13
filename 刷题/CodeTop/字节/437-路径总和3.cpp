/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 18:54:00
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 19:35:45
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
力扣T-112. 路径总和
给你二叉树的根节点 root 和一个表示目标和的整数 targetSum 。
判断该树中是否存在 根节点到叶子节点 的路径，这条路径上所有节点值相加等于目标和 targetSum 。
如果存在，返回 true ；否则，返回 false 。
叶子节点 是指没有子节点的节点。

113. 路径总和 II
给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有 从根节点到叶子节点 路径总和等于给定目标和的路径。
叶子节点 是指没有子节点的节点。

437. 路径总和 III
给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

示例 1：
    输入：root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
    输出：3
    解释：和等于 8 的路径有 3 条.
示例 2：
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    输出：3
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

// 1-回溯
// 每一条符合条件的路径的起始节点 可能是任一节点，因此要对所有节点进行操作
// 对某一个节点进行操作，就是以该节点为起始节点，一直向下找满足条件的路径，直到遇到空节点才返回
// 找到满足条件的路径(尾节点)，就对路径数进行+1，继续向下找看还有没有，直到遇到空节点，
// 然后将找到的路径数回栈时一起返回。

class Solution {
public:
    // 一步步详细递归寻找 (sum - root->val),直到找到与节点的val值相对应
    int findSum(TreeNode* root, long long sum) {
        if (root == nullptr) return 0;
        int res = 0;
        if (root->val == sum) res++;
        res += findSum(root->left, sum - root->val);
        res += findSum(root->right, sum - root->val);
        return res;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return 0;
        int ans = findSum(root, targetSum);
        // 因为题目要求不限起点，所以要遍历以每一个节点为开始的路线
        ans += pathSum(root->left, targetSum);
        ans += pathSum(root->right, targetSum);
        return ans;
    }
};