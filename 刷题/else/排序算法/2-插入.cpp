/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 09:49:58
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 10:39:12
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

//  插入排序
void InsertSort(std::vector<int> &nums,int n) {
    if (n <= 1) return;
    for(int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums [j-1]; --j) {
            std::swap(nums[j],nums[j-1]);
        }
    }
    cout << endl;
    cout << "插入排序完成" << endl;
}

int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    for (auto ele : a) cout << ele << ' ';

    InsertSort(a, a.size());

    for (auto ele : a) cout << ele << ' ';
    return 0; 
 }