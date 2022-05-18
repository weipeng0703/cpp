/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-17 10:23:06
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-17 14:36:24
 */
/*
力扣198. 打家劫舍
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内 能够偷窃到的最高金额。

213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同
时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

337. 打家劫舍 III（树状数组）
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

示例 1：
    输入: root = [3,2,3,null,3,null,1]
    输出: 7 
    解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7
示例 2：
    输入: root = [3,4,5,1,3,null,1]
    输出: 9
    解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
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
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 思路：
// dp数组长度为2，表示[偷当前节点得到的金额， 不偷当前节点得到的金额]
// 如果是偷当前节点，那么左右孩子就不能偷，val1 = cur->val + left[1] + right[1];
// 如果不偷当前节点，那么左右孩子就可以偷，到底偷不偷一定是选(偷或者不偷中)最大的，所以：
// val2 = max(left[0], left[1]) + max(right[0], right[1]);
// 最后当前节点的状态就是{val2, val1}; 即：{偷当前节点得到的最大金钱，不偷当前节点得到的最大金钱}

class Solution {
public:
    // 长度为2的dp数组，表示[偷当前节点得到的金额， 不偷当前节点得到的金额]
    vector<int> robTree(TreeNode* root) {
        if (root == nullptr) return vector<int>{0, 0};
        vector<int> left = robTree(root->left);
        vector<int> right = robTree(root->right);
        // 偷当前节点,就一定不能偷其左右子节点.所以加上子节点的（不偷其节点的金额）
        int ans1 = root->val + left[1] + right[1];
        // 不偷当前节点
        int ans2 = max(left[0], left[1]) + max(right[0], right[1]);
        return vector<int>{ans1, ans2};
    }
    int rob(TreeNode* root) {
        vector<int> dp = robTree(root);
        return max(dp[0], dp[1]);
    }
};


