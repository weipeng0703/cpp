/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 15:48:50
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 19:02:38
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

示例 1：
    输入：root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
    输出：[[5,4,11,2],[5,8,4,5]]
示例 2：
    输入：root = [1,2,3], targetSum = 5
    输出：[]
示例 3：
    输入：root = [1,2], targetSum = 0
    输出：[]
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
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void travel(TreeNode* root, int sum) {
        // 递归终止条件：遍历到了叶子节点且该加的数变为0了说明存在完整的一条路线符合题意
        if (!root->left && !root->right && sum == 0) ans.push_back(temp);
        
        if (root->left) {
            sum -= root->left->val;
            temp.push_back(root->left->val);
            travel(root->left, sum);
            sum += root->left->val;
            temp.pop_back();
        }
        if (root->right) {
            sum -= root->right->val;
            temp.push_back(root->right->val);
            travel(root->right, sum);
            sum += root->right->val;
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) return ans;
        temp.push_back(root->val);
        travel(root, targetSum - root->val);
        return ans;
    }
};