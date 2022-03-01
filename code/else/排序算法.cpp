#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp; 
 }
//  冒泡排序
void BubbleSort(std::vector<int> &nums) {
    for (int i = 1; i < 8; ++i) {
        for (int j = 1; j < 8 - i + 1; ++j) {
            if (nums[j] < nums[j-1]) 
            {
                std::swap(nums[j], nums[j-1]);
                }
            }
    }
    cout << "冒泡排序完成" << endl;
}
// 插入排序
void InsertSort(std::vector<int> &nums,int n) {
    if (n <= 1) return;
    for(int i = 0; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums [j-1]; --j) {
            std::swap(nums[j],nums[j-1]);
        }
    }
    cout << "插入排序完成" << endl;
}
// 选择排序
void SelectSort(std::vector<int> &nums,int n) {
    for (int i = 0; i < n; i++)
    {
        int mid = i;
        // 找到未排序的数组中最小的数nums[mid]
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[mid])
            {
                mid = j;
            }
        }
        swap(nums[mid], nums[i]);
    }
    cout << "选择排序完成" << endl;
}
int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    // BubbleSort(a);      // 冒泡排序
    InsertSort(a, 8);    // 插入排序
    // SelectSort(a, 8);       // 选择排序
    for (auto ele : a)
    {
        cout << ele << ' ';
    }
    
    return 0; 
 }