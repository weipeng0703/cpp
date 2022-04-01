/*
面试题 02.07. 链表相交
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
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
    ListNode(int x) : val(x), next(NULL) {}
};
// 1.通过集合set解决
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        set<ListNode*> st;
        while (headA != nullptr)
        {
            st.add(headA);
            headA = headA->next;
        }
        
        while (headB != nullptr)
        {
            if (set.find(headB))
            {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
// 2.双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;

        ListNode* A = headA, B = headB;
        while (A != B)
        {
            A = A != nullptr? A->next : headB;
            B = B != nullptr? B->next : headA;
        }
        return A;
    }
};