/*
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
调用 min、push 及 pop 的时间复杂度都是 O(1)。

示例:
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.min();   --> 返回 -3.
    minStack.pop();
    minStack.top();      --> 返回 0.
    minStack.min();   --> 返回 -2.
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

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (stk.empty() || x <= min_stk.top())
        {
            min_stk.push(x);
        }
        stk.push(x);
    }
    
    void pop() {
        if (stk.top() == min_stk.top())
        {
            min_stk.pop();
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int min() {
        return min_stk.top();
    }
private:
    stack<int> stk;
    // 设定一个辅助栈，记录当前数据栈的最小值 
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */