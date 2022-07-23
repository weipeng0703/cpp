/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 10:50:50
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 10:24:35
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

//  快速排序
void quickSort(std::vector<int> &nums,int left, int right) {
    if (left + 1 >= right) return;
    int first = left, last = right, key = nums[first];
    while (first < last) {
        while (first < last && nums[last] >= key) last--;
        nums[first] = nums[last];
        while (first < last && nums[first] <= key) first++;
        nums[last] = nums[first];
    }
    nums[first] = key;
    quickSort(nums, left, first);
    quickSort(nums, first + 1, right);
}

int main() {
    vector<int> a = {46, 75, 61, 87, 12, 43, 23, 54};
    for (auto ele : a) cout << ele << ' ';

    quickSort(a, 0, a.size() - 1);
    cout << endl;
    cout << "快速排序完成" << endl;

    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }