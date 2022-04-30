/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
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

//  1.迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        // 迭代法翻转链表
        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        // 进行完上面的反转过程后，curr指向空，pre指向最初链表的最后一位
        return pre;
    }
};
// 时间复杂度：O(n)，其中 n 是链表的长度。需要遍历链表一次。
// 空间复杂度：O(1)

// 2.递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* temp = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;       // 防止出现环
        return temp; 
    }
};
// 时间复杂度：O(n)，其中 n 是链表的长度。需要对链表的每个节点进行反转操作。
// 空间复杂度：O(n),递归调用栈空间，最多为n层