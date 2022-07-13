/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 10:36:30
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 10:39:34
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

//  选择排序
void SelectSort(std::vector<int> &nums,int n) {
    if (n <= 1) return;
    for(int i = 0; i < n; ++i) {
        int mid = i;
        for (int j = i + 1; j < n; j++) {
            // 筛选未排序区最小的数
            if (nums[j] < nums[mid]) mid = j;
        }
        std::swap(nums[mid], nums[i]);
    }
    cout << endl;
    cout << "选择排序完成" << endl;
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';

    SelectSort(a, a.size());

    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }