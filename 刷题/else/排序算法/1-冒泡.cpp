/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 09:39:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 09:44:21
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

template<class T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp; 
 }
//  冒泡排序
void BubbleSort(std::vector<int> &nums, int n) {
    if (n <= 1) return;
    bool flag;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j-1]) {
                std::swap(nums[j], nums[j-1]);
                flag = true;
            }
        }
        if (flag == false) break;
    }
    cout << endl;
    cout << "冒泡排序完成" << endl;
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';

    BubbleSort(a, a.size());      // 冒泡排序

    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }