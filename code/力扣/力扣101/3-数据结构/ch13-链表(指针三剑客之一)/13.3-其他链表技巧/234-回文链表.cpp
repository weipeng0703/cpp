/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true ；否则，返回 false 。

示例 1：
    输入：head = [1,2,2,1]
    输出：true
示例 2：
    输入：head = [1,2]
    输出：false
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// 1.双指针法
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> store;

        while (head != nullptr)
        {
            store.push_back(head->val);
            head = head->next;
        }
        
        for (int i = 0, j = store.size() - 1; i < j; i++, j--)
        {
            if (store[i] != store[j])
            {
                return false;
            }
            
        }
        return true;
    }
};

// 2.快慢指针
// 找中点->翻转一半->比对->还原（可有可无）
class Solution {
public:
    ListNode* find_mid(ListNode* head)      // 快慢指针法寻找链表中点
    {
        ListNode* p = head;
        ListNode* q = head;

        while (q->next != nullptr && q->next->next != nullptr)
        {
            p = p->next;
            q = q->next->next;
        }
        return p;
    }
    ListNode* reverse(ListNode* head)      // 翻转链表的迭代实现
    {
        ListNode* pre = nullptr;
        ListNode* curr = head;

        while (curr != nullptr)
        {
            ListNode* temp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
    bool val(ListNode* A, ListNode* B)     // 比较两个链表
    {
        while (B != nullptr)
        {
            if (A->val != B->val)
            {
                return false;
            }
            A = A->next;
            B = B->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return true;
        }
        // 寻找链表中点
        ListNode* slow_end = find_mid(head);
        ListNode* fast_start = slow_end->next;
        slow_end->next = nullptr;

        // 翻转后半部分
        fast_start = reverse(fast_start);

        // 比较
        bool flag = val(head, fast_start);

        // 还原链表
        // to be continued

        return flag;
    }
};