/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 

说明：

你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 

进阶：

你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。

示例：

    输入：
    ["MyQueue", "push", "push", "peek", "pop", "empty"]
    [[], [1], [2], [], [], []]
    输出：
    [null, null, null, 1, 1, false]

    解释：
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class MyQueue {
    stack<int> in, out;
public:
    // 构造函数
    MyQueue() {

    }
    // 辅助函数：用于翻转栈in->out
    void in2out()
    {
        if (out.empty())        // 判断输出栈是否为空
        {
            while (!in.empty())     // 遍历输入栈，将里面元素存入输出栈
            {
                int x = in.top();
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