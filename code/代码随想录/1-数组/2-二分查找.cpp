/*
力扣704-二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1：
    输入: nums = [-1,0,3,5,9,12], target = 9
    输出: 4
    解释: 9 出现在 nums 中并且下标为 4
示例 2：
    输入: nums = [-1,0,3,5,9,12], target = 2
    输出: -1
    解释: 2 不存在 nums 中因此返回 -1
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
// ！！！注意
// 1.使用二分法的前提条件：
//     1.数组为有序数组，
//     2.强调数组中无重复元素，因为一旦有重复元素，使用二分查找法返回的元素下标可能不是唯一的
// 2.二分法有两种写法——左闭右闭区间与左闭右开区间，养成习惯只写一种（自己倾向于写左闭右闭），不要混淆

// 1.二分查找
// 定义 target 是在一个在左闭右闭的区间里，也就是[left, right] （这个很重要非常重要）
    // while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
    // if (nums[middle] > target) right 要赋值为 middle - 1，
    // 因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0){
            return -1;
        }
        int left = 0, right = nums.size() - 1;
        while (left <= right){
            // 防止经典bug导致溢出
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            }else if (nums[mid] < target){
                left = ++mid;
            }else if (nums[mid] > target){
                right = --mid;
            }
        }
        return -1;
    }
};

// 版本二
// 定义 target 是在一个在左闭右开的区间里，也就是[left, right) ，那么二分法的边界处理方式则截然不同。
// 有如下两点：
    // while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的
    // if (nums[middle] > target) right 更新为 middle，
    // 因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，所以right更新为middle，
    // 即：下一个查询区间不会去比较nums[middle]
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
        while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // target 在左区间，在[left, middle)中
            } else if (nums[middle] < target) {
                left = middle + 1; // target 在右区间，在[middle + 1, right)中
            } else { // nums[middle] == target
                return middle; // 数组中找到目标值，直接返回下标
            }
        }
        // 未找到目标值
        return -1;
    }
};