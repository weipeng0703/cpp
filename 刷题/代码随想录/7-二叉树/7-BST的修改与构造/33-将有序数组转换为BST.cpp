/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-21 09:17:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-21 09:55:38
 */
/*
力扣108. 将有序数组转换为二叉搜索树
给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

// 注：其实这里不用强调平衡二叉搜索树，数组构造二叉树，构成平衡树是自然而然的事情，
// 因为大家默认都是从数组中间位置取值作为节点元素，一般不会随机取，所以想构成不平衡的二叉树是自找麻烦。

示例 1：
    输入：nums = [-10,-3,0,5,9]
    输出：[0,-3,9,-10,null,5]
    解释：[0,-10,5,null,-3,null,9] 也将被视为正确答案：
示例二：
    输入：nums = [1,3]
    输出：[3,1]
    解释：[1,null,3] 和 [3,1] 都是高度平衡二叉搜索树。
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
// 思路：根据数组构造一棵二叉树。本质就是寻找分割点，分割点作为当前节点，然后递归左区间和右区间。

// 1.想想给定一个数组如何画出二叉树：
// step1.将数组排序为有序递增数组
// step2.二分查找的中间节点即为当前根节点
// step3.左子树右子树根据步骤2不断递归
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        // mid已经用完，现在分别递归mid左右数组构建左右子树
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return helper(nums, 0, nums.size() - 1);
    }
};

// （该题可以类比4-修改与构造的T20-构造最大二叉树：
// 最大二叉树寻找的根节点是当前序列中最大的数字，构造二叉树是寻找当前递增序列中中间的数字）
// 构造最大二叉树
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;
        int maxIndex = left;
        for (int i = maxIndex + 1; i <= right; i++) {
            if (nums[i] > nums[maxIndex]) maxIndex = i;
        }
        TreeNode* root = new TreeNode(nums[maxIndex]);

        root->left = helper(nums, left, maxIndex - 1);
        root->right = helper(nums, maxIndex + 1, right);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return helper(nums, 0, nums.size() - 1);    // 左闭右闭区间
    }
};