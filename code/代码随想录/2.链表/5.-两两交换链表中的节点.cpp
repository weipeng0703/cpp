/*
力扣24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题
（即，只能进行节点交换）。

示例 1：
    输入：head = [1,2,3,4]
    输出：[2,1,4,3]
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        // 使用一个哑节点
        ListNode* dummpyNode = new ListNode(-1);
        dummpyNode->next = head;
        ListNode* temp = dummpyNode;

        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;

            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummpyNode->next;
    }
};

// 2.递归
class Solution {
public:
    void swapNode(ListNode* node1, ListNode* node2){
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* preHead = head->next;
        head->next = swap(preHead->next);
        preHead->next = head;
        return preHead;
    }
};