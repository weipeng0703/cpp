/*
力扣203. 移除链表元素
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

示例 1：
    输入：head = [1,2,6,3,4,5,6], val = 6
    输出：[1,2,3,4,5]
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
// 注意：要记得手动清理内存中被移除的链表节点（虽然不清理lc也能通过）

// 1.直接在原链表进行操作，头节点需要额外操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;
        // 删除头节点
       while (head && head->val == val)
       {
           ListNode* temp = head;
           head = head->next;
           delete temp;
       }
        // 删除非头节点
        ListNode* curr = head;
        while (curr && curr->next)
        {
            if (curr->next->val == val)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

// 2.创建哑节点，统一操作
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curr = dummyNode;
        while (curr->next)
        {
            if (curr->next->val == val)
            {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }
        return dummyNode->next;
    }
};

// 清理内存(lc测试用时更高而且内存消耗也高，没必要)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return nullptr;

        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* curr = dummyNode;
        while (curr->next)
        {
            if (curr->next->val == val)
            {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }
        head = dummyNode->next;
        delete dummyNode;
        return head;
    }
};