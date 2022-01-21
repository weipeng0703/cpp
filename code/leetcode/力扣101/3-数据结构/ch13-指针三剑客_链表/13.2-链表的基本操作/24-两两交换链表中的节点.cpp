/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。
你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换不能用值交换）。

示例 1:
    输入：head = [1,2,3,4]
    输出：[2,1,4,3]
示例 2：
    输入：head = []
    输出：[]
示例 3：
    输入：head = [1]
    输出：[1]
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
        ListNode* temphead = head->next;     // temphead变为头节点
        head->next = swapPairs(temphead->next);
        temphead->next = head;
        return temphead;
    }
};
// 2.迭代
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode tempNode = dummyNode;

        while (tempNode->next != nullpte && tempNode->next->next != nullpte)
        {
            ListNode *node1 = tempNode->next;
            ListNode *node2 = tempNode->next->next;

            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = node1;
        }
        return dummyNode->next;
    }
};