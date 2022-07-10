/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-03 14:46:49
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 10:19:21
 */
/*
力扣T-23. 合并K个升序链表
给你一个链表数组，每个链表都已经按升序排列
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
    输入：lists = [[1,4,5],[1,3,4],[2,6]]
    输出：[1,1,2,3,4,4,5,6]
    解释：链表数组如下：
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    将它们合并到一个有序链表中得到。
    1->1->2->3->4->4->5->6
示例 2：
    输入：lists = []
    输出：[]
示例 3：
    输入：lists = [[]]
    输出：[]
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

// 1-迭代
// 用ans记录已经合并的链表，每次循环将下一个链表合并
class Solution {
public:
    ListNode* merge2Lists (ListNode* a, ListNode* b) {
        if (!a) return b;
        if (!b) return a;
        ListNode dummy;
        ListNode* tail = &dummy;
        // aptr与bptr用于遍历两个链表中的节点
        ListNode *aptr = a, *bptr = b;
        // a和b链表都还没遍历完
        while (aptr && bptr) {
            if (aptr->val < bptr->val) {
                tail->next = aptr;
                aptr = aptr->next;
            } else {
                tail->next = bptr;
                bptr = bptr->next;
            }
            // tail继续去遍历下一个节点
            tail = tail->next;
        }
        // a或b链表有一个遍历完了，将另一个剩余的直接接上
        tail->next = aptr? aptr : bptr;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        if (lists.size() == 0) return ans;
        for (int i = 0; i < lists.size(); i++) {
            ans = merge2Lists(ans, lists[i]);
        }
        return ans;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        if (lists.size() == 0) return ans;
        for (int i = 0; i < lists.size(); i++) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};