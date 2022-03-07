/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
示例 1:
    输入: head = [4,5,1,9], val = 5
    输出: [4,1,9]
    解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
示例 2:
    输入: head = [4,5,1,9], val = 1
    输出: [4,5,9]
    解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.
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
// #include<algorithm>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 1.暴力
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
        {
            return nullptr;
        }
        else if(head->val == val)
        {
            head = head->next;
        }
        else{
            ListNode* temp = head;
            while (temp != nullptr && temp->next != nullptr)
            {
                if (temp->next->val == val)
                {
                    temp->next = temp->next->next;
                }
                temp = temp->next;
            }
        }
        return head;
    }
};
// 2.双指针
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head == nullptr)
        {
            return nullptr;
        }
        else if(head->val == val)
        {
            head = head->next;
        }
        else
        {
            ListNode* fast = head->next;
            ListNode* slow = head;

            while (fast != nullptr && slow != nullptr)
            {
                if (fast->val == val)
                {
                    slow->next = fast->next;
                }
                fast = fast->next;
                slow = slow->next;
            }
        }
        return head;
    }
};