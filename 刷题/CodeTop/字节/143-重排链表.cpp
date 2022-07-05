/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 22:22:04
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-05 22:37:41
 */
/*
力扣T-143. 重排链表
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1：
    输入：head = [1,2,3,4]
    输出：[1,4,2,3]
示例 2：
    输入：head = [1,2,3,4,5]
    输出：[1,5,2,4,3]
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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1-数组模拟
// 将原链表中所有节点放入数组中，之后按照新的顺序建立一个新链表
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) return;
        vector<ListNode*> temp;
        // 将原链表节点装入数组
        ListNode* cur = head;
        while (cur) {
            temp.push_back(cur);
            cur = cur->next;
        }
        // 重排链表
        cur = head;
        int i = 1, j = temp.size() - 1;
        int count = 0;
        while (i <= j) {
            if (count % 2 == 0) {
                cur->next = temp[j];
                j--;
            } else {
                cur->next = temp[i];
                i++;
            }
            count++;
            cur = cur->next;
        }
        cur->next = nullptr;    // 这一行必须得有
    }
};