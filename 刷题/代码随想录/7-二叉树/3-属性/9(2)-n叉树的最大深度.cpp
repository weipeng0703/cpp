/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-13 15:41:16
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-13 16:32:03
 */
/*
力扣559. N 叉树的最大深度
给定一个 N 叉树，找到其最大深度。
最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。
N 叉树输入按层序遍历序列化表示，每组子节点由空值分隔（请参见示例）。
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

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
// 1.递归深搜
// 精简写法
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == 0) return 0;
        int ans = 0;
        for (int i = 0; i < root->children.size(); i++) {
            ans = max(ans, maxDepth(root->children[i]));
        }
        return ans + 1;
    }
};
// 2.使用广搜进行层序遍历
class Solution {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) return 0;
        queue<Node*> que;
        que.push(root);
        int ans = 0;
        while (!que.empty()) {
            ans++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                Node* temp = que.front();
                que.pop();
                for (int i = 0; i < temp->children.size(); i++) {
                    if (temp->children[i]) que.push(temp->children[i]);
                }
            }
        }
        return ans;
    }
};