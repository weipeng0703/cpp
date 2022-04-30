/*
请定义一个队列并实现函数 max_value 得到队列里的最大值
要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
若队列为空，pop_front 和 max_value 需要返回 -1
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

// 1.暴力实现一个普通队列，查询时遍历计算
class MaxQueue {
public:
    int q[2000];
    int begin = 0, end = 0;

    MaxQueue() {

    }
    
    int max_value() {
        int ans = -1;
        for (int i = begin; i != end; i++)
        {
            ans = max(ans, q[i]);
        }
        return ans;
    }
    
    void push_back(int value) {
        q[end++] = value;
    }
    
    int pop_front() {
        if (begin == end)
        {
            return -1;
        }
        return q[begin++];
    }
};
// 时间复杂度：O(1)（插入，删除），O(n)（求最大值）。
// 插入与删除只需要普通的队列操作，为 O(1)，求最大值需要遍历当前的整个队列，最坏情况下为 O(n)。
// 空间复杂度：O(n)，需要用队列存储所有插入的元素。

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */

// 2、维护一个单调双端队列
class MaxQueue {
public:
    // q就是记录数据的队列
    // d记录队列的最大值，d首 即为当前队列q中的最大值
    // 队列就直接pop（默认队首）和push（默认队尾）和front（队首元素）
    queue<int> q;
    deque<int> d;
    MaxQueue() {

    }
    
    int max_value() {
        if(d.empty() || q.empty()) {
            return -1;
        }
        return d.front();
    }
    
    void push_back(int value) {
        // 在每次入队时，如果辅助队列 deque 队尾元素小于即将入队的元素 value，
        // 则将小于 value 的元素全部出队后，再将 value 入队；
        // 否则直接入队。
        while(!d.empty() && d.back() < value) {
            // 因为d的front是当前队列的最大值，所以pop时要从后往前pop，即pop_back
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }
    
    int pop_front() {
        if(q.empty()) {
            return -1;
        }
        int ans = q.front();
        // 出队时，若队首元素与辅助队列队首元素相同（当前要出队的元素是最大值），二者均出队；否则只是队列队首出队
        // 因为辅助队列要记录队列的最大值，所以除非队列中的最大值出列，辅助队列中的数据要留下记录最大值
        if(d.front() == ans) {
            // 弹出最大值在队首，所以用pop_front
            d.pop_front();
        }
        q.pop();
        return ans;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */