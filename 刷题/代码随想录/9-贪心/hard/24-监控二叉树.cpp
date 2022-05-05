/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-04 22:23:02
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-05 10:22:51
 */
/*
力扣968. 监控二叉树
给定一个二叉树，我们在树的节点上安装摄像头。
节点上的每个摄影头都可以监视其父对象、自身及其直接子对象。
计算监控树的所有节点所需的最小摄像头数量。

示例 1:
    输入：[0,0,null,0,0]
    输出：1
    解释：如图所示，一台摄像头足以监控所有节点。
示例 2:
    输入：[0,0,null,0,null,0,null,null,0]
    输出：2
    解释：需要至少两个摄像头来监视树的所有节点。 上图显示了摄像头放置的有效位置之一。
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

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 1.贪心
// https://programmercarl.com/0968.%E7%9B%91%E6%8E%A7%E4%BA%8C%E5%8F%89%E6%A0%91.html#%E6%80%9D%E8%B7%AF
// 0 - 无覆盖
// 1 - 有摄像头
// 2 - 有覆盖
class Solution {
public:
    int ans = 0;
    int travel(TreeNode* root) {
        if (root == nullptr) return 2;

        int left = travel(root->left);
        int right = travel(root->right);

        if (left == 2 && right == 2) return 0;
        if (left == 0 || right == 0) {
            ans++;
            return 1;
        }
         // 这个判断条件一定要放在最后，其他情况前段代码均已覆盖
        if (left == 1 || right == 1) return 2;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if (travel(root) == 0) ans++;
        return ans;
    }
};