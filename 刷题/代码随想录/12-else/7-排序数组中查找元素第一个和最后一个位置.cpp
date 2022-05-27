/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-27 10:41:38
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-27 11:29:05
 */

/*
力扣34. 在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
进阶：
    你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：
    输入：nums = [5,7,7,8,8,10], target = 8
    输出：[3,4]
示例 2：
    输入：nums = [5,7,7,8,8,10], target = 6
    输出：[-1,-1]
示例 3：
    输入：nums = [], target = 0
    输出：[-1,-1]
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

// 注：看到排序数组，第一印象 二分法

// 1-暴力遍历
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) return vector<int>{-1, -1};
        int left = 0, right = nums.size() - 1;
        while (nums[left] != target) left++;
        while (nums[right] != target) right--;
        return vector<int>{left, right};
    }
};

// 2-二分
class Solution {
public:
    int leftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBorder = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 寻找左边界，nums[middle] == target的时候更新right(往后减逐步往左靠)
            if (nums[mid] >= target) {
                right = mid - 1;
                leftBorder = right;
            } else {
                left = mid + 1;
            }
        }
        return leftBorder;
    }
    int rightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightBorder = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // 寻找右边界，nums[middle] == target的时候更新left(往前加逐步往右靠)
            if (nums[mid] <= target) {
                left = mid + 1;
                rightBorder = left;
            } else {
                right = mid - 1;
            }
        }
        return rightBorder;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) return vector<int>{-1, -1};
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) return vector<int>{-1, -1};
        return vector<int>{leftBorder(nums, target) + 1, rightBorder(nums, target) - 1};
    }
};