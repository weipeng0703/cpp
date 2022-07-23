/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 14:49:53
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 15:10:36
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
/*
基本概念
1.队列是一个有序列表，可以用数组或是链表来实现。
2.遵循先入先出的原则。即：先存入队列的数据，要先取出。后存入的要后取出

代码实现
队列本身是有序列表，若使用数组的结构来存储队列的数据，则队列数组的声明如下：

1.队列的最大容量 maxSize 。
2.因为队列的输出、输入是分别从前后端来处理，因此需要两个变量 front 及 rear分别记录队列前后端的下标， 
front 会随着数据输出而改变，而 rear 则是随着数据输入而改变。
3.为了显示队列元素，用length记录队列的元素个数。
4.用数组arr来记录存储数据。
5.除此之外，数组模拟队列需要定义几个重要的方法，即成员函数：
    出队列操作getQueue
    显示队列的情况showQueue
    查看队列头元素headQueue
    退出系统exit
    判断队列是否已满
    判断队列是否为空
*/
class queue{
private:
    //声明基本参数
    int maxSize;// 表示数组的最大容量
    int front;//队列头
    int rear;//队列尾
    int *arr;//用于存放数据，模拟队列
    int length;//用于记录元素个数
public:
    //队列构造函数，确定数组大小，为数组分配内存
    //初始化队列首尾元素
    queue(int arrMaxSize){
        maxSize = arrMaxSize;
        arr = new int[maxSize];
        length = 0;
        //指向队列头部，分析出front是指向队列头的前一个位置.
        front = -1;
        //指向队列尾，指向队列尾的数据(即队列最后一个数据)
        rear = -1;
    };
    //析构函数 释放内存
    ~queue() {
        delete arr;
    }
    //判断队列是否满
    bool isFull() {
        // 队尾指针指向数组最大位置时，表明队列已满。
        return rear = maxSize - 1;
    }
    //判断队列是否为空
    bool isEmpty() {
        // 队首指针和队尾指针指向同一位置时，表示队列已空。
        return front == rear;
    }
    //向队列中添加元素
    // ddQueue 的处理需要有两个步骤：
    // 1-将尾指针往后移：rear+1 , 当 front == rear ,队列为空
    // 2-若尾指针 rear 小于队列的最大下标 maxSize-1，则将数据存入 rear 所指的数组元素中，否则无法存入数据。 
    // rear == maxSize - 1，队列已满
    void addQueue(int n) {
        if (isFull()) cout << "队列已满，无法添加数据" << endl;
        rear++;
        arr[rear] = n;
        length++;
    }
    //从队列中取出元素
    // 1-判断队列是否为空
    // 2-将队首指针后移一位，然后取出当前位置的元素值。
    int getQueue() {
        if (isEmpty()) throw "队列为空，不能取数据";
        front++;
        length--;
        int val = arr[front];
        return val;
    }
    //获取队列元素个数
    int getLength() {
        return length;
    }
    //显示队列所有元素
    // 从队首开始，遍历length个队列元素，并打印出来。
    void showQueue() {
        if (isEmpty()) cout << "队列为空，不能打印数据" << endl;
        for (int i = front + 1; i < front + 1 + getLength(); i++) {
            cout << "arr[" << i << "] = " << arr[i] << endl;
        }
    }
    //显示队列头元素
    // 队首指针不动，显示指针后一位置的元素值。注意，显示队首元素，并不是出队，元素仍然存储在队列中。
    int headQueue() {
        if (isEmpty()) throw "队列为空，不能取数据";
        return arr[front + 1];
    }
}