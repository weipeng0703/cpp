/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 18:40:19
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 19:28:51
 */
/*
力扣T-92. 反转链表 II
给你单链表的头指针 head 和两个整数 left 和 right ，其中 left <= right 。
请你反转从位置 left 到位置 right 的链表节点，返回 反转后的链表 。
 
示例 1：
    输入：head = [1,2,3,4,5], left = 2, right = 4
    输出：[1,4,3,2,5]
示例 2：
    输入：head = [5], left = 1, right = 1
    输出：[5]
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

// 1.断连翻转后重新连接
class Solution {
public:
    void reverseLinkedList (ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        // 1.找到left的前一个节点
        for (int i = 0; i < left - 1; i++) pre = pre->next;
        // 2.找到right节点
        ListNode* rightnode = pre;
        for (int i = 0; i < right - left + 1; i++) rightnode = rightnode->next;
        // 3.截取链表
        ListNode* leftnode = pre->next;
        ListNode* cur = rightnode->next;        // right后面的第一个节点
        // 切断原链表的链接
        pre->next = nullptr;
        rightnode->next = nullptr;
        // 4.翻转链表
        reverseLinkedList(leftnode);
        // 5.重新连接链表
        pre->next = rightnode;
        leftnode->next = cur;
        return dummy->next;
    }
};
// 2-头插法
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        // 1.找到left的前一个节点pre
        for (int i = 0; i < left - 1; i++) pre = pre->next;
        // 2.头插，依次将后面的元素排到pre后面
        ListNode* cur = pre->next;
        for (int i = 0; i < right - left; i++) {
            // (1)定下接下来要移到头上的节点
            ListNode* temp = cur->next;
            // (2)cur与temp换位
            cur->next = temp->next;
            // (3)temp移动到pre后面第一个位置
            temp->next = pre->next;
            pre->next = temp;
        }
        return dummy->next;
    }
};