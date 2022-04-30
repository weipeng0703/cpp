/*
给定一个二叉树其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的next指针。下图为一棵有9个节点的二叉树。

树中从父节点指向子节点的指针用实线表示，从子节点指向父节点的用虚线表示
示例一：
输入：{8,6,10,5,7,9,11},8
输出：9
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
using namespace std; 

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
// 1.暴力解法：求树的根节点，进行中序遍历将节点存入vector,在vector中查找结点
class Solution {
public:
    void inorder(TreeLinkNode* root, vector<TreeLinkNode*>& temp)
    {
        if (root == nullptr)
        {
            return;
        }
        inorder(root->left, temp);
        temp.push_back(root);
        inorder(root->right, temp);
    }
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        
        TreeLinkNode* root = nullptr;
        TreeLinkNode* temp = pNode;
        while (temp)
        {
            root = temp;
            temp = temp->next;
        }

        vector<TreeLinkNode*> temp_vec;
        inorder(root, temp_vec);

        for (int i = 0; i < temp_vec.size(); i++)
        {
            if (temp_vec[i] == pNode)
            {
                return temp_vec[++i];
            }
            
        }
        return nullptr;
    }
};
// 时间复杂度：
// 第一步：最坏为O(N), N为整棵树结点的个数。第二步：O(N), 第三步：最坏为O(N),
// 所以整的时间复杂度：3*O(N)即O(N)

// 2.分情况讨论解法
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (!pNode) {
            return pNode;
        }

        // 当前结点右孩子结点，
        // 那么下一节点就是：右孩子结点的最左孩子结点,
        // 如果右孩子结点没有左孩子就是自己
        if (pNode->right) {
            pNode = pNode->right;
            while (pNode->left) {
                pNode = pNode->left;
            }
            return pNode;
        }

        // 当前结点是父亲结点的左孩子或右孩子
        while (pNode->next) {
            TreeLinkNode *root = pNode->next;
            if (root->left == pNode) {
                return root;
            }
            pNode = pNode->next;
        }

        // 树尾节点，没有下一位
        return nullptr;
    }
};