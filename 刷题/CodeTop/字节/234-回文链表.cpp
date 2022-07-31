/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-31 19:37:08
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-31 20:32:17
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
力扣T-234. 回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
示例 1：
    输入：head = [1,2,2,1]
    输出：true
示例 2：
    输入：head = [1,2]
    输出：false
*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 1.将链表数据存入数组再用双指针判断
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        vector<int> temp;
        while (head) {
            temp.push_back(head->val);
            head = head->next;
        }
        int i = 0, j = temp.size() - 1;
        while (i <= j) {
            if (temp[i] != temp[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};
// 2-使用快慢指针寻找链表中点，翻转链表后面一部分然后比较
class Solution {
public:
    // // 迭代翻转链表
    // ListNode* reverseNode(ListNode* head) {
    //     ListNode* pre = nullptr;
    //     ListNode* cur = head;
    //     while (cur) {
    //         ListNode* temp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = temp;
    //     }
    //     return pre;
    // }
    // 递归翻转链表
    ListNode* tempReverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
        return tempReverse(cur, temp);
    }
    ListNode* reverseNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        return tempReverse(nullptr, head);
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        ListNode* pre = head;
        ListNode* fast = head;
        ListNode* slow = head;
        // 寻找链表中点
        // pre是为了记录slow前面的一个节点，分割链表的时候令他的next为空
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // 分割链表
        pre->next = nullptr;
        ListNode* cur1 = head;
        ListNode* cur2 = reverseNode(slow);
        // 比较
        while (cur1 && cur2) {
            if (cur1->val != cur2->val) return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};