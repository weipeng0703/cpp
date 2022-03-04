  // https://www.runoob.com/w3cnote/heap-sort.html
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

// 快速排序
// 快排分区函数
int Paritition1(std::vector<int>& A, int low, int high) {
    int pivot = A[low];
    while (low < high)
    {
        //右指针 从右向左扫描 将⼩于piv的放到左边
        while (low < high && A[high] >= pivot) {
            --high;
        }
        A[low] = A[high];
        //左指针 从左向右扫描 将⼤于piv的放到右边
        while (low < high && A[low] <= pivot) {
            ++low;
        }
        A[high] = A[low];
    }
    // 更新枢纽位置
    A[low] = pivot;
    return low;
}
//快排母函数
void QuickSort(std::vector<int>& A, int low, int high) 
{
    if (low < high)
    {
        int pivot = Paritition1(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
    cout << "快速排序完成" << endl;
}
// 归并排序
// 归并排序的时间复杂度任何情况下都是 O(nlogn)，归并排序不是原地排序算法

// 堆排序
// 堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
// 堆排序可以说是一种利用堆的概念来排序的选择排序。分为两种方法：
// 大顶堆：每个节点的值都大于或等于其子节点的值，在堆排序算法中用于升序排列；
// 小顶堆：每个节点的值都小于或等于其子节点的值，在堆排序算法中用于降序排列；
// 堆排序的平均时间复杂度为 Ο(nlogn)。
void max_heapify(vector<int>& arr, int start, int end) {
    // 建立父节点和其子节点
    int dad = start;
    int son = dad * 2 + 1;
    // 若子节点在范围内，进行比较
    while (son <= end) { 
        // 先比较两个子节点，选择最大的
        if (son + 1 <= end && arr[son] < arr[son + 1]) 
            son++;
        // 若父节点>子节点表示调整完毕，跳出函数
        if (arr[dad] > arr[son]) 
            return;
        // 否则交换父子节点内容，继续子节点和孙子节点比较
        else { 
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(vector<int>& arr, int len) {
    // 初始化，i从最后一个父节点进行调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    // 先将第一个元素和已经排好的元素前一位做交换，再重新调整刚刚调整的元素之前的元素，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
    cout << "堆排序结束" << endl;
}
int main() {
    vector<int> a = {34,66,2,5,95,4,46,27};
    // BubbleSort(a);      // 冒泡排序
    // InsertSort(a, 8);    // 插入排序
    // SelectSort(a, 8);       // 选择排序
    // QuickSort(a, 0, 7);      // 快速排序
    heap_sort(a, 8);        // 堆排序
    for (auto ele : a)
    {
        cout << ele << ' ';
    }
    
    return 0; 
 }