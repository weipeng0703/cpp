/*
力扣232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false
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

class MyQueue {
    stack<int> in, out;
public:
    // 构造函数
    MyQueue() {

    }
    // 辅助函数：用于翻转栈in->out
    void in2out() {
        if (out.empty()) {
            while (!in.empty()) {
                int x = in.top();
                // 以下两步可翻转
                in.pop();
                out.push(x);
            }
        }
    }
    // 插入元素
    void push(int x) {
        in.push(x);
    }
    // 返回被弹出的元素
    int pop() {
        in2out();
        int x = out.top();
        out.pop();
        return x;
    }
    // 返回队首的元素
    int peek() {
        in2out();
        return out.top();
    }
    // 判断队列是否为空
    bool empty() {
        return in.empty() && out.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */