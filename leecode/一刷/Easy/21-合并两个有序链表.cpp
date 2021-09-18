/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1：

输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
*/

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

// 思路：递归方式


// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         if (l1 == NULL)
//         {
//             return l2;
//         }
//         else if (l2 == NULL)
//         {
//             return l1;
//         }
//         else if(l1->val <= l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else if(l1->val >= l2->val)
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
        
//     }
// };