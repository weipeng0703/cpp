/*
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：

    输入：lists = [[1,4,5],[1,3,4],[2,6]]
    输出：[1,1,2,3,4,4,5,6]
    解释：链表数组如下：
    [
    1->4->5,
    1->3->4,
    2->6
    ]
    将它们合并到一个有序链表中得到。
    1->1->2->3->4->4->5->6
示例 2：

    输入：lists = []
    输出：[]
示例 3：

    输入：lists = [[]]
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
// 前置：合并两个有序链表a,b 二者长度均为n，要求时间复杂度O(n)，空间复杂度O(1)，即原地排序
// 原理：原地调整链表元素的next指针进行合并
ListNode* merge2Lists(ListNode *a, ListNode *b)
{
    if (!a)
    {
        return b;
    }
    else if (!b)
    {
        return a;
    }
    ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
    while (aPtr && bPtr)
    {
        if (aPtr->val < bPtr->val)
        {
            tail->next = aPtr;
            aPtr = aPtr->next;
        }
        else ()
        {
            tail->next = bPtr;
            bPtr = bPtr->next;
        }
        tail = tail->next;
    }
    tail->next = (aPtr? aPtr: bPtr);
    return head.next;
}

// 方法一：顺序合并
// 我们可以想到一种最朴素的方法：
// 用一个变量 ans 来维护已经合并的链表，第 i 次循环把第 i 个链表和 ans 合并，答案保存到 ans 中。
class Solution {
public:
    ListNode* merge2Lists(ListNode *a, ListNode *b)
    {
        if (!a)
        {
            return b;
        }
        else if (!b)
        {
            return a;
        }
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while (aPtr && bPtr)
        {
            if (aPtr->val < bPtr->val)
            {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }
            else ()
            {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = nullptr;
        for (int i = 0; i < list.size(); i++)
        {
            ans = merge2Lists(ans, list[i]);
        }
        return ans;
    }
};

// 方法二：使用优先队列
// 需要维护当前每个链表没有被合并的元素的最前面一个，k 个链表就最多有 k 个满足这样条件的元素，
// 每次在这些元素里面选取 val 属性最小的元素合并到结果中。
// 在选取最小元素的时候，我们可以用优先队列来优化这个过程。
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const 
        {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) 
                q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); 
            q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) 
                q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};
