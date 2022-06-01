/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-29 10:39:25
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-31 18:36:39
 */
/*
力扣143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
    输入：head = [1,2,3,4]
    输出：[1,4,2,3]
示例 2：
    输入：head = [1,2,3,4,5]
    输出：[1,5,2,4,3]
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

// 1.数组模拟：将所有节点放入数组，之后双指针法重构新链表
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> temp;
        ListNode* cur = head;
        if (cur == nullptr) return;
        while (cur != nullptr) {
            temp.push_back(cur);
            cur = cur->next;
        }
        cur = head;
        int i = 1, j = temp.size() - 1;
        int count = 0;
        while (i <= j) {
            if (count % 2 == 0) {
                cur->next = temp[j];
                j--;
            } else {
                cur->next = temp[i];
                i++;
            }
            cur = cur->next;
            count++;
        }
        cur->next = nullptr;
    }
};
// 2.双向队列模拟：将所有节点放入双向队列，之后分别弹出来重构新链表
class Solution {
public:
    void reorderList(ListNode* head) {
        deque<ListNode*> temp;
        ListNode* cur = head;
        if (cur == nullptr) return;
        while (cur->next != nullptr) {
            // 下标大的节点在back，小的节点在front
            temp.push_back(cur->next);
            cur = cur->next;
        }
        cur = head;
        int count = 0;
        ListNode* node;
        while (temp.size()) {
            // count为偶的时候处理靠后的节点
            if (count % 2 == 0) {
                node = temp.back();
                temp.pop_back();
            } else {
                node = temp.front();
                temp.pop_front();
            }
            count++;
            cur->next = node;
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};
// 3.将链表分割成两个链表，然后把第二个链表反转，之后在通过两个链表拼接成新的链表。
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // 第一段链表
        ListNode* head1 = head;
        // 第二段链表
        ListNode* head2;
        head2 = slow->next;
        slow->next = nullptr;
        head2 = reverseList(head2);
        
        // 将head1与head2交替生成新的链表
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        ListNode* cur = head;
        cur1 = cur1->next;
        int count = 0;
        while (cur1 && cur2) {
            if (count % 2 == 0) {
                cur->next = cur2;
                cur2 = cur2->next;
            } else {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            count++;
            cur = cur->next;
        }
        if (cur2 != nullptr) cur->next = cur2;
        if (cur1 != nullptr) cur->next = cur1;
    }
};