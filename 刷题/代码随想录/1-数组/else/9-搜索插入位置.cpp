/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-28 11:25:53
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-28 11:45:20
 */
/*
力扣35. 搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

示例 1:
    输入: nums = [1,3,5,6], target = 5
    输出: 2
示例 2:
    输入: nums = [1,3,5,6], target = 2
    输出: 1
示例 3:
    输入: nums = [1,3,5,6], target = 7
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

// 1-暴力
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
        // 分别处理如下三种情况
        // 目标值在数组所有元素之前
        // 目标值等于数组中某一个元素
        // 目标值插入数组中的位置
            if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        // 目标值在数组所有元素之后的情况
        return nums.size(); // 如果target是最大的，或者 nums为空，则返回nums的长度
    }
};

// 2-二分
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.size() == 0) return 1;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [left, right] == [0, -1],此时答案为 right + 1 == -1 + 1 == 0
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， return right + 1
        return right + 1;
    }
};