/*
描述
用两个栈来实现一个队列，使用n个元素来完成 n 次在队列尾部插入整数(push)和n次在队列头部删除整数(pop)的功能。 
队列中的元素为int类型。保证操作合法，即保证pop操作时队列内已有元素。

示例一：
    输入：
    ["PSH1","PSH2","POP","POP"]

    返回值：
    1,2

    说明：
    "PSH1":代表将1插入队列尾部
    "PSH2":代表将2插入队列尾部
    "POP“:代表删除一个元素，先进先出=>返回1
    "POP“:代表删除一个元素，先进先出=>返回2     

示例二：
    输入：
    ["PSH2","POP","PSH1","POP"]

    返回值：
    2,1
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class Solution
{
public:
    void stack1Tostack2()
    {
        if (stack2.empty()) 
        {
            while(!stack1.empty())
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
        int x = stack2.top();
        stack2.pop();
        return x;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};