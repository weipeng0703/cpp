/*
统计一个数字在排序数组中出现的次数。

示例 1:
    输入: nums = [5,7,7,8,8,10], target = 8
    输出: 2
示例 2:
    输入: nums = [5,7,7,8,8,10], target = 6
    输出: 0
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
using namespace std; 

// 1.巧妙方法
// lower_bound( )和upper_bound( )都是利用二分查找的方法在一个排好序的数组中进行查找的。
// 在从小到大的排序数组中，
// lower_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个 大于或等于num 的数字，找到返回该数字的地址，不存在则返回end。
// 通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
// upper_bound( begin,end,num)：从数组的begin位置到end-1位置二分查找第一个 大于num 的数字，找到返回该数字的地址，不存在则返回end。
// 通过返回的地址减去起始地址begin,得到找到数字在数组中的下标。
class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 如果数组未排序的话应该先用sort()对数组排序
        return upper_bound(nums.begin(), nums.end(), target) - lower_bound(nums.begin(), nums.end(), target);
    }
};

// 2.二分查找
class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower)
    {
        int left = 0, right = nums.size() - 1, ans = nums.size();
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (nums[mid] > target || (lower && nums[mid] >= target))
            {
                right = mid - 1;
                ans = mid;
            }
            else
            {
                left = mid + 1;
            }
            
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        // 查找第一个 大于等于 target的位置
        int leftIndex = binarySearch(nums, target, true);
        // 查找第一个 严格大于 target的位置
        int rightIndex = binarySearch(nums, target, false) - 1;
        if (leftIndex <= rightIndex && rightIndex <= nums.size() && nums[leftIndex] == target && nums[rightIndex] == target)
        {
            return rightIndex - leftIndex + 1;
        }
        return 0;
    }
};

// 3.直接方法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int count = 0;
        for (int ele : nums)
        {
            if (ele == target)
            {
                count++;
            }
            else if (ele > target)
            {
                break;
            }
        }
        return count;
    }
};