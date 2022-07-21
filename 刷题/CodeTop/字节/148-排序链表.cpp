/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-20 16:08:59
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-20 17:19:55
 */
/*
力扣T-148. 排序链表
给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。

示例 1：
    输入：head = [4,2,1,3]
    输出：[1,2,3,4]
示例 2：
    输入：head = [-1,5,3,4,0]
    输出：[-1,0,3,4,5]
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

// 平均时间复杂度为O(nlogn)的算法：快些归队(快排，希尔，归并排序，堆排序)
// 1. 暴力将链表节点的数值放到vector中sort再遍历链表对节点按照vector顺序赋值
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> vec;
        ListNode* node = head;
        while (node != nullptr) {
            vec.push_back(node->val);
            node = node->next;
        }
        sort(vec.begin(), vec.end());
        node = head;
        for (int i = 0; i < vec.size(); i++) {
            node->val = vec[i];
            node = node->next;
        }
        return head;
    }
};
// 2-堆排序
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) return nullptr;
        priority_queue<int, vector<int>, greater<int>> q;
        auto temp = head;
        while (temp) {
            q.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while (temp) {
            temp->val = q.top();
            q.pop();
            temp = temp->next;
        }
        return head;
    }
};
// 3-归并
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* sub = new ListNode(0);
        ListNode* ptr = sub;
        // ListNode* node;
        while (l1 && l2) {
            auto& node = l1->val < l2->val ? l1 : l2;
            ptr->next = node;
            node = node->next;
            ptr = ptr->next;
        }
        ptr->next = l1 ? l1 : l2;
        return sub->next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 切链, 将链表分为slow之后的链表和由head到fast的链表
        fast = slow->next;
        slow->next = nullptr;
        return merge(sortList(head), sortList(fast));
    }
};