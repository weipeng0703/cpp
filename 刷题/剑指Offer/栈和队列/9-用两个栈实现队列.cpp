/*
用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。
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
using namespace std; 

class Solution
{
public:
    void stack1Tostack2()
    {
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                int x = stack1.top();
                stack1.pop();
                stack2.push(x);
            }
        }
    }
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        stack1Tostack2();
        int i = stack2.top();
        stack2.pop();
        return i;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

class CQueue {
public:
    // 注意：两个栈需要先初始化
    CQueue() {
         while (!stk1.empty()) {
            stk1.pop();
        }
        while (!stk2.empty()) {
            stk2.pop();
        }
    }
    void stack1tostack2(){
        if (stk2.empty())
        {
            while (!stk1.empty())
            {
                int temp = stk1.top();
                stk1.pop();
                stk2.push(temp);
            }
        }
    }
    
    void appendTail(int value) {
        stk1.push(value);
    }
    
    int deleteHead() {
        stack1tostack2();
        // 注意判断栈2是否为空
        if(stk2.empty())
        {
            return -1;
        }
        int temp = stk2.top();
        stk2.pop();
        return temp;
    }
private:
    stack<int> stk1;
    stack<int> stk2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */