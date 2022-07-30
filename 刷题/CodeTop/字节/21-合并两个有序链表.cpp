/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 09:57:07
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-30 10:59:40
 */
/*
力扣T-23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列
请你将所有链表合并到一个升序链表中，返回合并后的链表。

21. 合并两个有序链表
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：
    输入：l1 = [1,2,4], l2 = [1,3,4]
    输出：[1,1,2,3,4,4]
示例 2：
    输入：l1 = [], l2 = []
    输出：[]
示例 3：
    输入：l1 = [], l2 = [0]
    输出：[0]
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
// 本题就是T-23的辅助函数

// 1-迭代
// 用ans记录已经合并的链表，每次循环将下一个链表合并
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (!list2 && !list1) return nullptr;
        ListNode dummy;
        ListNode* tail = &dummy;
        ListNode* a = list1;
        ListNode* b = list2;
        while (a && b) {
            if (a->val < b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};

// 2-递归
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (!list2 && !list1) return nullptr;
        if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else if (list1->val >= list2->val)
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
    }
};