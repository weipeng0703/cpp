/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-01 09:47:28
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-01 10:23:07
 */
/*
力扣T-160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
如果两个链表不存在相交节点，返回 null 。
图示两个链表在节点 c1 开始相交：
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

// 1-哈希表
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        unordered_set<ListNode*> s;
        while (headA) {
            s.insert(headA);
            headA = headA->next;
        }
        while (headB) {
            if (s.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

// 2-双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        ListNode* A = headA;
        ListNode* B = headB;

        while (A != B) {
            A = A == nullptr? headB : A->next;
            B = B == nullptr? headA : B->next;
        }
        return A;
    }
};




