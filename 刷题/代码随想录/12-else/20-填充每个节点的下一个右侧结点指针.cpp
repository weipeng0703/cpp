/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-02 15:07:22
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-03 09:08:49
 */
/*
力扣116 给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
初始状态下，所有 next 指针都被设置为 NULL。

示例 1：
输入：root = [1,2,3,4,5,6,7]
输出：[1,#,2,3,#,4,5,6,7,#]
解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，以指向其下一个右侧节点，如图 B 所示。
    序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
示例 2：
    输入：root = []
    输出：[]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<queue>
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
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 1.迭代（层序遍历）可以做,且思想更直观
// 但是用到了额外的队列空间，不符合题意
class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> que;
        if (root) que.push(root);
        while (!que.empty()) {
            int size = que.size();      // 每一层的大小
            for (int i = 0; i < size; i++) {
                Node* node = que.front();
                que.pop();
                // 因为当前que里都是该层的节点
                // 所以如果i是最后一位，其next为nullptr；否则是该层的下一个元素（即que.front()）
                if (i == size - 1) node->next = nullptr;
                else node->next = que.front();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        }
        return root;
    }
};

// 2. 递归(前序遍历)
class Solution {
public:
    void travel(node* root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right) {
            if (root->next) root->right->next = root->next->left;
            else root->right->next = nullptr;
        }
        travel(root->left);
        travel(root->right);
        return;
    }
    Node* connect(Node* root) {
        travel(root);
        return root;
    }
};