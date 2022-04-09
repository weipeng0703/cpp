/*
力扣225. 用队列实现栈
请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：
    void push(int x) 将元素 x 压入栈顶。
    int pop() 移除并返回栈顶元素。
    int top() 返回栈顶元素。
    boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
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

class MyStack {
private:
    queue<int> q1;      // 用来进行操作
    queue<int> q2;      // 用来进行备份
public:
    MyStack() {

    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int size = q1.size();
        // 将q1中元素除最后一位外清空，将他们复制到q2中保存
        size--;
        while (size--) {
            q2.push(q1.front());
            q1.pop();
        }
        // q1中剩余的元素即为栈顶元素
        int result = q1.front();
        q1.pop();
        // 将目前q2中的元素复制到q1中
        q1 = q2;
        // 清空q2
        while (!q2.empty()) q2.pop();
        return result;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */