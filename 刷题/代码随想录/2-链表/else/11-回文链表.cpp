/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-29 09:44:31
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-29 10:38:07
 */
/*
力扣234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
    输入：head = [1,2,2,1]
    输出：true
示例 2：
    输入：head = [1,2]
    输出：false
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

// 1.数组模拟：将所有节点的val放入数组判断是否回文
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        vector<int> temp;
        while (head != nullptr) {
            temp.push_back(head->val);
            head = head->next;
        }
        int left = 0, right = temp.size() - 1;
        while (left <= right) {
            if (temp[left] != temp[right]) return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

// 2.快慢指针翻转（迭代或递归）后半部分链表
class Solution {
public:
    // 迭代
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* temp;
    //     ListNode* cur = head;
    //     ListNode* pre = nullptr;

    //     while (cur) {
    //         temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = temp;
    //     }
    //     // 最后cur已经变成空节点，所以返回其前一个节点即pre
    //     return pre;
    // }

    // 递归
    ListNode* tempReverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return tempReverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        return tempReverse(nullptr, head);
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        ListNode* pre = head;
        ListNode* slow = head;
        ListNode* fast = head;
        // fast走两步到链表尾，slow走一步到链表中间
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 分割链表
        pre->next = nullptr;
        ListNode* cur1 = head;
        // 翻转后半部分链表
        ListNode* cur2 = reverseList(slow);
        // 比较两个链表的节点
        while (cur1) {
            if (cur1->val != cur2->val) return false;
            else {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }
        return true;
    }
};