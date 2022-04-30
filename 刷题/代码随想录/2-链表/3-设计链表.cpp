/*
力扣707. 设计链表
在链表类中实现这些功能：
    get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
    addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
    addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
    addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
    deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
示例 1：
    MyLinkedList linkedList = new MyLinkedList();
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1,2);   //链表变为1-> 2-> 3
    linkedList.get(1);            //返回2
    linkedList.deleteAtIndex(1);  //现在链表是1-> 3
    linkedList.get(1);            //返回3
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

// 创建虚拟头节点统一操作
class MyLinkedList {
public:
    // 定义链表节点结构体
    struct LinkedNode
    {
        int val;
        LinkedNode* next;
        LinkedNode(int val) : val(val), next(nullptr){}
    };
    // 初始化链表
    MyLinkedList() {
        dummyNode = new LinkedNode(0);
        size = 0;
    }
    // 获取第index个链表元素
    int get(int index) {
        if (index < 0 || size - 1 < index)
        {
            return -1;
        }
        LinkedNode* curr = dummyNode -> next;
        while (index--)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    // 在链表头插入元素
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = dummyNode->next;
        dummyNode->next = newNode;
        size++;
    }
    // 在链表尾插入元素
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = dummyNode;
        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        size=++;
    }
    // 在index前插入元素
    void addAtIndex(int index, int val) {
        if (index > size)
        {
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* curr = dummyNode;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
    // 删除第index个节点
    void deleteAtIndex(int index) {
        if (index >= size || index < 0)
        {
            return;
        }
        LinkedNode* curr = dummyNode;
        while (index--)
        {
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        return size--;
    }
    // 打印链表
    void printLinkedList() {
        LinkedNode* curr = dummyNode;
        while (curr->next)
        {
            cout << curr->next->val << endl;
            curr = curr->next;
        }
    }
private:
    int size;
    LinkedNode* dummyNode;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */