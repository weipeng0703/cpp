/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-29 20:59:50
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-29 21:39:32
 */
/*
力扣T-103. 二叉树的锯齿形层序遍历
给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。
（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

示例 1：
    输入：root = [3,9,20,null,null,15,7]
    输出：[[3],[20,9],[15,7]]
示例 2：
    输入：root = [1]
    输出：[[1]]
示例 3：
    输入：root = []
    输出：[]
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

// 1-正常层序遍历后对答案中奇数元素reverse
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(temp);
        }
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 1) reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

// 2-双端队列方法
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        bool left_flag = true;      // 标志位
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            // 定义一个双端队列存储当前层的值，用双端队列是方便按层存值调换方向
            deque<int> dlist;
            int n = que.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = que.front();
                que.pop();
                if(left_flag) dlist.push_back(node->val);   // 尾插
                else dlist.push_front(node->val);           // 头插
                //读取下一层节点值进入队列(从左至右这个是不变的)
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            // 规定好双端队列的头尾后，上面不管是尾插还是头插顺序就能对得上
            ans.push_back(vector<int>{dlist.begin(), dlist.end()});
            left_flag = !left_flag;  //标志位转换
        }
        return ans;
    }
};