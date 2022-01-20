/*
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1:
    输入：head = [1,2,3,4,5]
    输出：[5,4,3,2,1]
示例 2：
    输入：head = [1,2]
    输出：[2,1]
示例 3：
    输入：head = []
    输出：[]
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
// 1.迭代
// https://leetcode-cn.com/problems/reverse-linked-list/solution/shi-pin-jiang-jie-die-dai-he-di-gui-hen-hswxy/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode prev = nullptr;
        ListNode curr = head;

        while (curr != nullptr)
        {
            ListNode* temp = curr->next;    // 一个临时值用于记录中间信息
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};

// 2.递归
// 符合递归的三个条件：
// 1.一个大问题拆成两个子问题：头节点 与 除了头节点之外剩余的节点
// 2.子问题求解方式跟大问题一样
// 3.存在最小子问题
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // 递归终止条件
        if (!head || head->next = nullptr)
        {
            return head;
        }
        // 传递子问题
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};