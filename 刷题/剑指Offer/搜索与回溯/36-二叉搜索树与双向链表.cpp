/*
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。
要求不能创建任何新的节点，只能调整树中节点指针的指向。
题目具体细节见：
https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
// 深搜中序遍历
class Solution {
public:
    Node *pre, *head;
    void dfs(Node* cur){
        if (cur == nullptr)
        {
            return;
        }
        // 左
        dfs(cur->left);
        // 中
        if (pre != nullptr)
        {
            pre->right = cur;
        }
        else
        {
            // head只在遍历树中第一个节点时用到，确定链表的头节点
            head = cur;
        }
        cur->left = pre;
        pre = cur;
        // 右
        dfs(cur->right);
    }
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
        {
            return nullptr;
        }
        dfs(root);
        // 中序遍历结束后，head一直不变指向头节点，pre指向尾节点
        // 所以将他俩的指针指向修改即可
        head->left = pre;
        pre->right = head;
        return head;
    }
};