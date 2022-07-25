/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-25 19:54:30
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-25 20:35:25
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
#include<unordered_map>
#include<priority_queue>
using namespace std; 
/*
如果链表有环，如何判断两个链表是否相交
*/
// 分析：如果有环且两个链表相交，则两个链表都有共同一个环，即环上的任意一个节点都存在于两个链表上。
// 因此，就可以判断一链表上的快慢指针相遇的那个节点，在不在另一条链表上。
// 注意：
// 1.无环链表和有环链表是不可能相交的;
// 2.两个有环链表若相交，其“整个环上”的所有node一定都重合;
// 3.有环链表的相交，情况只有2种：相交于”环上”或相交于”不是环的部分”
// https://blog.csdn.net/gulaixiangjuejue/article/details/85395701

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.快慢指针判断某链表上是否有环并记录入环节点
ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
        if (fast == nullptr) return nullptr;
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            fast = head;
            while (fast != slow) {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
}
//判断两个带环链表是否相交,相交的话返回交点，否则返回nullptr
    // 1-两者都无环，node1与node2均返回nullptr二者相等，无交点
    // 2-一个无环返回nullptr，一个有环返回入环节点，最后返回nullptr
    // 3-二者均有环但不相交，返回nullptr
    // 4-二者均有环且相交，返回相交节点
ListNode* isIntersectWithLoop(ListNode* h1, ListNode* h2) {
    //判断链表带不带环，并保存入环节点
    ListNode* node1 = detectCycle(h1);
    ListNode* node2 = detectCycle(h2);
    if (node1 == node2) return node1;
    else {
        ListNode* temp = node1->next;
        while (temp != node1) {
            if (temp == node2) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
}