/*
力扣206.翻转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
示例 1：
    输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]
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

// 1.迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* temp;
        while (cur)
        {
            // temp为下一个待翻转的节点
            // 保留他,反转之后让他成为下一个cur
            // 思想类似于交换两个数时找一个temp暂存某一个数
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        // 注意：循环结束后pre指向原链表最后一个节点，cur指向原链表最后一个节点的后一个节点，即空节点
        // 所以最后要返回pre
        return pre;
    }
};

// 2.递归
class Solution {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if (cur == nullptr) return pre;

        ListNode* temp = cur->next;
        cur->next = pre;

        reverse(cur, temp);
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        return reverse(nullptr, head);
    }
};