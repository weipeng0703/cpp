/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
示例 1:
    输入：1->2->4, 1->3->4
    输出：1->1->2->3->4->4
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
// 1.双指针
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 一定要用一个新的节点，采用哑节点的方式
        ListNode* dummy = new ListNode(0), *pre = dummy;
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }
        else if (l1 == nullptr && l2 != nullptr)
        {
            return l2;
        }
        else if (l1 != nullptr && l2 == nullptr)
        {
            return l1;
        }
        else
        {
            while (l1 && l2)
            {
                if (l1->val <= l2->val)
                {
                    pre->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    pre->next = l2;
                    l2 = l2->next;
                }
                pre = pre->next;
            }
        }
        // 当某一支合并结束后，直接将另一只剩余部分都接上
        pre->next = l1? l1 : l2;
        return dummy->next;
    }
};
// 2.递归,非常简洁
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL && l2 != NULL)
            return l2;
        if (l1 != NULL && l2 == NULL)
            return l1;
        // 如果1的头节点大于2，则返回结果以2为头节点
        if (l1->val >= l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        else{
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
};