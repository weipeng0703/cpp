/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-25 20:35:39
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-25 22:06:19
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
力扣-912. 排序数组
给你一个整数数组 nums，请你将该数组升序排列。

示例 1：
    输入：nums = [5,2,3,1]
    输出：[1,2,3,5]
示例 2：
    输入：nums = [5,1,1,2,0,0]
    输出：[0,0,1,1,2,5]
*/ 

// 1. 快排-最后一个样例超时(没有随机选择枢纽)
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
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
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// 1. 快排优化（增添随机化枢纽）
class Solution {
public:
    void quickSort(vector<int>& nums, int left, int right) {
        if (left >= right) return;
        int first = left, last = right;
        // 基于随机的原则选择枢纽
        int x = rand() % (right - left + 1) + left; 
        swap(nums[left], nums[x]);
        int key = nums[left];

        while (first < last) {
            while (first < last && nums[last] >= key) last--;
        nums[first] = nums[last];
            while (first < last && nums[first] <= key) first++;
        nums[last] = nums[first];
        }
        nums[first] = key;
        quickSort(nums, left, first);
        quickSort(nums, first + 1, right);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
// 2-归并
class Solution {
public:
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
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        mergeSort(nums, ans, 0, nums.size() - 1);
        return ans;
    }
};
// 3-堆排序使用库函数
class Solution {
public:
    void heapSort(vector<int>& nums) {
        // 从小到大排序用小根堆
        priority_queue<int, vector<int>, greater<int>> tempHeap;
        // 从大到小排序用大根堆
        // priority_queue<int, vector<int>, less<int>> tempHeap;
        for (int x : nums) tempHeap.push(x);
        for (int i = 0; i <nums.size(); i++) {
            int temp = tempHeap.top();
            tempHeap.pop();
            nums[i] = temp;
            } 
    }
    vector<int> sortArray(vector<int>& nums) {
        // vector<int> ans(nums.size(), 0);
        heapSort(nums);
        return nums;
    }
};
// 4-堆排序，自己建堆
class Solution {
public:
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
    vector<int> sortArray(vector<int>& nums) {
        // vector<int> ans(nums.size(), 0);
        heapSort(nums, nums.size());
        return nums;
    }
};