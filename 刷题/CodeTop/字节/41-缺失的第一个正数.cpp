/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 11:16:16
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 15:35:25
 */
/*
力扣-41. 缺失的第一个正数
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。

示例 1：
    输入：nums = [1,2,0]
    输出：3
示例 2：
    输入：nums = [3,4,-1,1]
    输出：2
示例 3：
    输入：nums = [7,8,9,11,12]
    输出：1
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

// 1. 原地哈希
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            // 只需要在乎数组中1-n的数字即可，不用关心负数
            while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] -  1]) swap(nums[i], nums[nums[i] -  1]);
        }
        for (int i = 0; i < n; i++) {
            if (i + 1 != nums[i]) return i + 1;
        }
        return n + 1;
    }
};