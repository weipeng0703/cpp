// 题目
/*
两个栈实现一个队列
*/

// 解答
#include<iostream>
#include<stack>
using namespace std;

class Solution
{
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    void push(int node)
    {
        stack1.push(node);
    }
    int pop()
    {
        if (stack2.size() != 0)
        {
            int temp = stack2.top();
            stack2.pop();
            return temp;
        }
        
        else
        {
            while (stack1.size() != 0)
            {
                int temp = stack1.top();
                stack1.pop();
                stack2.push(temp);
            }
            return pop();
        }
        
    }
};