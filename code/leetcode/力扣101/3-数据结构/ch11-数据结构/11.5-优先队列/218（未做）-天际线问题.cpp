/*
城市的天际线是从远处观看该城市中所有建筑物形成的轮廓的外部轮廓。
给你所有建筑物的位置和高度，请返回由这些建筑物形成的 天际线 。

每个建筑物的几何信息由数组 buildings 表示，其中三元组 buildings[i] = [lefti, righti, heighti] 表示：
lefti 是第 i 座建筑物左边缘的 x 坐标。
righti 是第 i 座建筑物右边缘的 x 坐标。
heighti 是第 i 座建筑物的高度。
天际线 应该表示为由 “关键点” 组成的列表，格式 [[x1,y1],[x2,y2],...] ，并按 x 坐标 进行 排序 。
关键点是水平线段的左端点。列表中最后一个点是最右侧建筑物的终点，y 坐标始终为 0 ，仅用于标记天际线的终点。
此外，任何两个相邻建筑物之间的地面都应被视为天际线轮廓的一部分。

注意：输出天际线中不得有连续的相同高度的水平线。
例如 [...[2 3], [4 5], [7 5], [11 5], [12 7]...] 是不正确的答案；
三条高度为 5 的线应该在最终输出中合并为一个：[...[2 3], [4 5], [12 7], ...]

示例一：
    输入：buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
    输出：[[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
    解释：
    图 A 显示输入的所有建筑物的位置和高度，
    图 B 显示由这些建筑物形成的天际线。图 B 中的红点表示输出列表中的关键点。
示例二：
    输入：buildings = [[0,2,3],[2,5,3]]
    输出：[[0,3],[5,0]]
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
