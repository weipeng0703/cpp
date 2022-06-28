/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-28 19:53:00
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-28 19:59:56
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