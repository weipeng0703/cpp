/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-16 09:32:26
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-16 10:49:27
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
using namespace std; 

// vector类型递归
void mergeSort(std::vector<int> &nums, std::vector<int> &temp, int low, int high) {
    // 每部分只剩一个数时结束
    if (low >= high) return;
    int len = high - low, mid = low + (high - low) / 2;
    int start1 = low, end1 = mid, start2 = mid + 1, end2 = high;
    mergeSort(nums, temp, start1, end1);
    mergeSort(nums, temp, start2, end2);
    int index = low;
    // 只有两者都符合才能进行循环，有一个不符合条件循环结束，
    // 表示某一部分的数字遍历完了，剩下的只需要将另一部分的数字加入temp
    while (start1 <= end1 && start2 <= end2) {
        temp[index++] = nums[start1] < nums[start2]? nums[start1++] : nums[start2++];
    }
    while (start1 <= end1) temp[index++] = nums[start1++];
    while (start2 <= end2) temp[index++] = nums[start2++];
    for (int i = low; i <= high; i++) nums[i] = temp[i];
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';
    vector<int> temp(a.size(), 0);
    mergeSort(a, temp, 0, a.size() - 1);
    cout << endl;
    cout << "归并排序完成" << endl;
    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }