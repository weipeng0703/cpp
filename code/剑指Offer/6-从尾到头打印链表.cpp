/*
输入一个链表的头节点，按链表从尾到头的顺序返回每个节点的值（用数组返回）。

示例一：
输入：{1,2,3}
输出：[3,2,1]
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
using namespace std; 

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
// 1.从前向后遍历链表保存节点值到数组后使用reverse翻转（不修改链表结构）
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ans;
        if (head == nullptr)
        {
            return ans;
        }

        ListNode* temp = head;
        while (temp != nullptr)
        {
            ans.push_back(temp->val);
            temp = temp->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// 2.反转链表
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        
        vector<int> ans;
        while (pre != nullptr)
        {
            ans.push_back(pre->val);
            pre = pre->next;
        }
        return ans;
    }
};
