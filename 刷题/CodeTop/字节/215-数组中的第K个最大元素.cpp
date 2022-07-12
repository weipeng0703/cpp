/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-28 19:53:00
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-11 22:27:58
 */
/*
力扣T-215. 数组中的第K个最大元素
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
    输入: [3,2,1,5,6,4] 和 k = 2
    输出: 5
示例 2:
    输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
    输出: 4
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

// 1-暴力sort(),但要考虑到特殊情况
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.size() == 1 && k == 1) return nums[0];
        else if (nums.size() == 1 && k > 1) return -1;
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};

// 2-利用快排的partition操作
// 左右挖坑互填写法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)  {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        while (true) {
            int idx = partition(nums, l, r);
            if (idx == k - 1) return nums[idx];
            else if (idx < k - 1) l = idx + 1;
            else r = idx - 1;
        }
    }
    // 左右挖坑互填
    int partition(vector<int> & nums, int l, int r) {
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] <= pivot) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] >= pivot) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;
        return l;
    }
};
// 注：如果partition()这样写则是求 TopK小 的问题
int partition(vector<int> & nums, int l, int r) {
    int pivot = nums[l];
    while (l < r) {
        while (l < r && nums[r] >= pivot) r--;
        nums[l] = nums[r];
        while (l < r && nums[l] <= pivot) l++;
        nums[r] = nums[l];
    }
    nums[l] = pivot;
    return l;
}

// 3-堆排序
// （1）大根堆调库
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> maxHeap;
        for (int x : nums) maxHeap.push(x);
        for (int i = 0; i < k - 1; i++) maxHeap.pop();
        return maxHeap.top();
    }
};

// (2)手写实现大根堆
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k)  {
        int n = nums.size();
        build_maxHeap(nums);
        for (int i = 0; i < k - 1; i++) {
            swap(nums[0], nums[n - 1 - i]);
            adjust_down(nums, 0, n - 1 - i - 1);
        }
        return nums[0];
    }
    void build_maxHeap(vector<int> & nums) {
        int n = nums.size();
        for (int root = n / 2; root > -1; root--) adjust_down(nums, root, n - 1);
    }

    void adjust_down(vector<int> & nums, int root, int hi) {
        if (root > hi) return;
        int t = nums[root];
        int child = 2 * root + 1;
        while (child <= hi) {
            if (child + 1 <= hi && nums[child] < nums[child + 1]) child++;
            if (t > nums[child]) break;
            nums[root] = nums[child];
            root = child;
            child = 2 * root + 1;
        }
        nums[root] = t;
    }
};