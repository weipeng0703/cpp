/*
力扣19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
    输入：head = [1,2,3,4,5], n = 2
    输出：[1,2,3,5]
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
// 双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return nullptr;

        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode* slow = dummyNode;
        ListNode* fast = dummyNode;

        while (n-- && fast)
        {
            fast = fast->next;
        }
        // 一定要再将fast后移一位
        fast = fast->next;

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        // 注意：有可能列表中只有一个元素而他正好被删掉
        // 此时就不能返回head了
        // 应该返回dummyNode的下一个元素
        return dummyNode->next;
    }
};