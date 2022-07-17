/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-16 10:59:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-16 15:00:45
 */
  // https://www.runoob.com/w3cnote/heap-sort.html
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std; 

// 1-调用库
void heapSort(vector<int>& nums) {
    // 从小到大排序用小根堆
    priority_queue<int, vector<int>, greater<int>> tempHeap;
    // 从大到小排序用大根堆
    // priority_queue<int, vector<int>, less<int>> tempHeap;
    for (int x : nums) tempHeap.push(x);
    for (int i = 0; i <nums.size(); i++){
        int temp = tempHeap.top();
        tempHeap.pop();
        nums[i] = temp;
    } 
}
// 2-自己建堆

// 对于有一定顺序的堆，当前第i个结点取根左右的最大值
void heapify(vector<int>& nums, int n, int i) {
    int left = i * 2 + 1, right = i * 2 + 2;
    int max = i;
    if (left < n && nums[left] > nums[max]) max = left;
    if (right < n && nums[right] > nums[max]) max = right;
    if (max != i) {
        std::swap(nums[max], nums[i]);
        heapify(nums, n, max);
    }
}
// 建立大根堆，从树的倒数第二层第一个结点开始，对每一个节点进行heapify操作然后向上走
void heapBuild(vector<int>& nums, int n) {
    int temp = (n - 2) / 2;
    for (int i = temp; i >= 0; i--) heapify(nums, n, i);
}
void heapSort(vector<int>& nums, int n) {
    heapBuild(nums, n);
    for (int i = 0; i < n; i++) {
        std::swap(nums.front(), nums[n - i - 1]);
        heapify(nums, n - i - 1, 0);
    }
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';
    // heapSort(a);    // 用库函数

    int n = a.size();
    heapSort(a, a.size());   // 自己建堆
    cout << endl;
    cout << "堆排序完成" << endl;
    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }