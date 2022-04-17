/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-17 10:05:38
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-17 11:20:03
 */
/*
力扣654. 最大二叉树
给定一个不重复的整数数组 nums 。 最大二叉树 可以用下面的算法从 nums 递归地构建:
创建一个根节点，其值为 nums 中的最大值。
递归地在最大值 左边 的 子数组前缀上 构建左子树。
递归地在最大值 右边 的 子数组后缀上 构建右子树。
返回 nums 构建的 最大二叉树 。
 
该题示例：
https://leetcode-cn.com/problems/maximum-binary-tree/
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
// 1.递归
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        // 构造一棵树
        TreeNode* ans = new TreeNode(-1);
        if (nums.size() == 1) {
            ans->val = nums[0];
            return ans;
        }
        // 求出当前nums区间内的最大值及其索引
        int maxVal = 0, indexMaxVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) {
                if (nums[i] > maxVal) {
                maxVal = nums[i];
                indexMaxVal = i;
            }
                /*
                // 不能用这种写法，这样每次循环i都会更新，不会保存最大值的索引
                maxVal = nums[i];
                indexMaxVal = i;
                */ 
            }
        }
        // 最大值即为根节点的val
        ans->val = maxVal;
        // 最大值下标的左区间构造左子树
        if (indexMaxVal > 0) {
            vector<int> vecLeft(nums.begin(), nums.begin() + indexMaxVal);
            ans->left = constructMaximumBinaryTree(vecLeft);
        }
        // 最大值下标的右区间构造右子树
        if (indexMaxVal < (nums.size() - 1)) {
            vector<int> vecRight(nums.begin() + indexMaxVal + 1, nums.end());
            ans->right = constructMaximumBinaryTree(vecRight);
        }
        return ans;
    }
};
// 2.递归简洁写法+节省空间
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left >= right) return nullptr;
        
        // 遍历nums区间寻找最大值的索引
        int indexMaxVal = left;
        for (int i = indexMaxVal + 1; i < right; i++) {
            if (nums[i] > nums[indexMaxVal]) indexMaxVal = i;
        }
        // 树的根节点val即为最大值
        TreeNode* ans = new TreeNode(nums[indexMaxVal]);
        ans->left = helper(nums, left, indexMaxVal);
        ans->right = helper(nums, indexMaxVal + 1, right);
        return ans;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};