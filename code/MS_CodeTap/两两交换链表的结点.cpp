/*
力扣T24-两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
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
// 1.递归
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* temp = head->next;
        head->next = swapPairs(temp);
        temp->next = head;
        return temp;
    }
};
// 2.迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        ListNode* dummpyNode = new ListNode(-1);
        dummpyNode ->next = head;
        ListNode* temp = dummpyNode;

        while (temp->next != nullptr && temp->next->next != nullptr)
        {
            ListNode* node1 = temp->next;
            ListNode* node2 = temp->next->next;

            // 交换之前的节点关系是 temp -> node1 -> node2，
            // 交换之后的节点关系要变成 temp -> node2 -> node1，因此需要进行如下操作。
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            // temp指向node1，继续进行后两个结点的交换
            temp = node1;
        }
        return dummpyNode->next;
    }
};