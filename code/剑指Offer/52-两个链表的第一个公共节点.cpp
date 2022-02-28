/*
输入两个链表，找出它们的第一个公共节点。
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
#include<unordered_set>
#include<algorithm>
using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
// 1.使用哈希表存储任一链表的节点，再访问第二个链表，看是否存在相同的节点：
// 存在则输出它，如果遍历完后仍然不存在相同节点，则不存在相交节点
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;
        ListNode* temp = headA;
        // 存储任一链表中节点
        while (temp != nullptr)
        {
            visited.insert(temp);
            temp = temp->next;
        }
        temp = headB;
        // 遍历另一链表中节点看set中是否存在
        while (temp != nullptr)
        {
            if (visited.count(temp))
            {
                // 存在的话输出他
                return temp;
            }
            temp = temp->next;
        }
        // 遍历完另一个链表不存在的话说明二者不相交
        return nullptr;
    }
};
// 时间:O(n+m)，m与n分别为两个链表的长度，遍历两个链表
// 空间:O(n)，n为第一次遍历的链表大小

// 2.双指针
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }
        
        ListNode* A = headA, *B = headB;
        while (A != B)
        {
            // 若A与B节点不为空则各自向下走一步，若为空则走到另一个链表的头
            A = (A != nullptr? A->next : headB);
            B = (B != nullptr? B->next : headA);
        }
        return A;
    }
};
// 时间:O(n+m)，m与n分别为两个链表的长度，遍历两个链表
// 空间:O(1)，没有使用额外空间
