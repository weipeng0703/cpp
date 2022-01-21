/*
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

示例 1:
    输入：l1 = [1,2,4], l2 = [1,3,4]
    输出：[1,1,2,3,4,4]
示例 2：
    输入：l1 = [], l2 = []
    输出：[]
示例 3：
    输入：l1 = [], l2 = [0]
    输出：[0]
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        else if (l2 == NULL)
        {
            return l1;
        }
        else if(l1->val <= l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else if(l1->val >= l2->val)
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        
    }
};

// 2.迭代
// 从零创建一个新的头节点，然后从头开始比较l1与l2的节点，哪个小将头节点指向其
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 记录新建的链表头，最后返回时返回它
        ListNode* prehead = new ListNode(0);

        ListNode prev = prehead;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
            }
            else if (l1->val >= l2->val)
            {
                prev->next = l2;
                l2 = l2->next;
            }
            // 将prev向后移动一位指向新加进来的节点
            prev = prev->next;
        }
        // 循环结束后最多有一个分支未被合并，直接将链表末尾指向它即可
        prev->next = (l1 == nullptr? l2 : l1);

        return prehead;
    }
};