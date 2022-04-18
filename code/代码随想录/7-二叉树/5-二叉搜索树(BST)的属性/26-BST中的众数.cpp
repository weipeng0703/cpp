/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-18 10:57:02
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-18 15:04:24
 */
/*
力扣501. 二叉搜索树中的众数
给你一个含重复值的二叉搜索树（BST）的根节点 root ，找出并返回 BST 中的所有 众数（即，出现频率最高的元素）。
如果树中有不止一个众数，可以按 任意顺序 返回。
假定 BST 满足如下定义：
结点左子树中所含节点的值 小于等于 当前节点的值
结点右子树中所含节点的值 大于等于 当前节点的值
左子树和右子树都是二叉搜索树


示例 1：
    输入：root = [1,null,2,2]
    输出：[2]
示例 2：
    输入：root = [0]
    输出：[0]
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

// 1. 对于所有树的通用解法
class Solution {
private:

void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // 前序遍历
    if (cur == NULL) return ;
    map[cur->val]++; // 统计元素频率
    searchBST(cur->left, map);
    searchBST(cur->right, map);
    return ;
}
bool static cmp (const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> map; // key:元素，value:出现频率
        vector<int> result;
        if (root == NULL) return result;
        // 1.遍历树，将数的节点值与其出现的次数保留到map中
        searchBST(root, map);
        // 2.将map中的数据保存到vector中
        vector<pair<int, int>> vec(map.begin(), map.end());
        // 3.对vector排序，选出出现次数最多的节点
        sort(vec.begin(), vec.end(), cmp); // 给频率排序
        result.push_back(vec[0].first);
        // 4.vector的第一位是出现次数最多的，从下一位开始遍历，寻找出现次数同样多的节点
        for (int i = 1; i < vec.size(); i++) {
            // 取最高的放到result数组中
            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
            else break;
        }
        return result;
    }
};

// 2.BST的解法
class Solution {
private:
    int count = 0;
    int maxCount = 0;
    TreeNode* pre = nullptr;
    vector<int> ans;
    void helper(TreeNode* root) {
        if (root == nullptr) return;
        // 左
        helper(root->left);
        // 中
        if(pre == nullptr) count = 1;
        else if (pre->val == root->val) count++;
        else count = 1;
        pre = root;             // ！！！

        if (count == maxCount) ans.push_back(root->val);
        if (count > maxCount) {
            maxCount = count;
            ans.clear();        // ！！！
            ans.push_back(root->val);
        }
        // 右
        helper(root->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) return ans;
        // ans.clear();
        helper(root);
        return ans;
    }
};