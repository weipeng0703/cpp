/*
输入一个链表，输出该链表中倒数第k个节点。
为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
示例：
    给定一个链表: 1->2->3->4->5, 和 k = 2.
    返回链表 4->5.
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
#include<unordered_map>
// #include<algorithm>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 1.顺序查找
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode* temp = nullptr;
        int n = 0;
        // 统计链表节点个数
        for (temp = head; temp!= nullptr; temp = temp->next)
        {
            n++;
        }
        // 倒数第k个节点即为正数第n-k个节点
        for (temp = head; n - k > 0; n--)
        {
            temp = temp->next;
        }
        return temp;
    }
};
// 2.快慢指针，其思想跟上面方法其实类似；都是通过记录一个步数再减少该步数达到行走规定步数
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode* fast = nullptr;
        ListNode* slow = nullptr;
        while (k-- >= 0)
        {
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};