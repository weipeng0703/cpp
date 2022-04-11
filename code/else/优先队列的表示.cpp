/*
 * @Descripttion: My project
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-01-11 20:11:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-11 14:39:44
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
#include<priority_queue>
#include <memory>
using namespace std; 
 
int main()
{
    // priority_queue<int> priorityQueue;   // 默认为从大到小
    priority_queue<int, vector<int>, greater<int> > priorityQueue;      // 从小到大

    priorityQueue.push(10);
    priorityQueue.push(12);
    priorityQueue.push(11);
    priorityQueue.push(5);

    while (!priorityQueue.empty()) {
        cout << priorityQueue.top() << endl;
        priorityQueue.pop();
    }
    return 0;
}