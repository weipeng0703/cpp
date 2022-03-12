/*
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。

设计一个支持以下两种操作的数据结构：
void addNum(int num) - 从数据流中添加一个整数到数据结构中。
double findMedian() - 返回目前所有元素的中位数。

示例 1:
    ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
    [[],[1],[2],[],[3],[]]
    输出：[null,null,null,1.50000,null,2.00000]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// 如果直接使用排序算法排序后再求中位数，时间复杂度为O(NlogN)
// 使用堆能将其减小为O(logN)
class MedianFinder {
public:
    // 大顶堆存储数据中偏小一半的值
    priority_queue<int, vector<int>, less<int>> maxHeap;
    // 小顶堆存储数据中偏大一半的值
    priority_queue<int, vector<int>, greater<int>> minHeap;
    /** initialize your data structure here. */
    MedianFinder() {

    }
    // 添加元素的过程中，维持大顶堆中元素个数始终 大于等于 小顶堆
    void addNum(int num) {
        // 所以如果当前两个堆数据个数相等，大根堆添加元素
        // 方法是：先将数据插入小顶堆，得到堆顶的最小值后，将其推入大顶堆，此时他是大顶堆的堆首
        if (maxHeap.size() == minHeap.size())
        {
            minHeap.push(num);
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }
        // 若当前两个堆数据个数不等，小根堆添加元素
        // 方法是：先将数据插入大顶堆，得到堆顶的最大值后，将其推入小顶堆，此时他是小顶堆的堆首
        else
        {
            maxHeap.push(num);
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size())
        {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else
        {
            return maxHeap.top() * 1.0;
        }
        
    }
};
// 时间复杂度：
// 查找中位数 O(1) ： 获取堆顶元素使用 O(1) 时间；
// 添加数字 O(logN) ： 堆的插入和弹出操作使用 O(logN) 时间。
// 空间复杂度 O(N) ： 
// 其中 N 为数据流中的元素数量，小顶堆 A 和大顶堆 B 最多同时保存 N 个元素。


/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */