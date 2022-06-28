/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-28 16:26:36
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-28 19:23:39
 */
/*
力扣T-25. K 个一组翻转链表
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。
k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

示例 1：
    输入：head = [1,2,3,4,5], k = 2
    输出：[2,1,4,3,5]
示例 2：
    输入：head = [1,2,3,4,5], k = 3
    输出：[3,2,1,4,5]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
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

class Solution {
public:
    // 辅助函数-迭代翻转一个子链表，返回其首尾
    pair<ListNode*, ListNode*> reverseList(ListNode* head, ListNode* tail) {
        ListNode* p = head;
        ListNode* prev = tail->next;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(-1);
        hair->next = head;
        ListNode* pre = hair;
        while (true) {
            // tail表示当前要翻转的这一部分链表的最后一个节点
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于k
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (!tail) return hair->next;
            }
            // nex为当前要翻转的一部分链表后的首个节点
            ListNode* nex = tail->next;
            pair<ListNode*, ListNode*> res = reverseList(head, tail);
            head = res.first;
            tail = res.second;
            // 将翻转后的链表首尾连回原链表
            pre->next = head;
            tail->next = nex;
            // 确定接下来要翻转的一部分链表
            // pre表示这一部分链表前面的一个节点，类似完整链表的hair节点
            // head表示这一部分链表的头节点
            pre = tail;
            head = tail->next;
        }
        return hair->next;
    }
};