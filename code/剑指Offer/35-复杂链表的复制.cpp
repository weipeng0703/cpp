/*
LC-138
请实现 copyRandomList 函数，复制一个复杂链表。
在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
题目解释：
根本不知道这个链表具体长什么样子，只能通过遍历这个链表来得到它的信息，来推它是长什么样，（示例的图其实是看不见的），
推完之后，就得到（和示例那些图 ）结构一样的链表
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
// #include<algorithm>
using namespace std; 

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// 题目中如果涉及记忆性，可以优先考虑哈希表
//  1.哈希+回溯
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node* temp = head;
        unordered_map<Node*, Node*> hash;
        // 构建 原节点->新节点 的映射
        while (temp != nullptr)
        {
            // 先构建出原链表中存在的节点，不管next和random关系
            hash[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        // 构建新链表的 next 和 random 指向
        while (temp != nullptr)
        {
            // 新链表中节点的next与random指向即为原链表中对应节点的next与random
            hash[temp]->next = hash[temp->next];
            hash[temp]->random = hash[temp->random];
            temp = temp->next;
        }
        // 返回新链表的头节点
        return hash[head];
    }
};
// 时间:O(n)，两次遍历原链表
// 空间:O(n)，哈希表的空间开销