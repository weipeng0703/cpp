/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-26 15:02:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-26 15:08:33
 */

/*
力扣27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

力扣283. 移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
请注意 ，必须在不复制数组的情况下原地对数组进行操作。
示例 1：
    输入: nums = [0,1,0,3,12]
    输出: [1,3,12,0,0]
示例 2:
    输入: nums = [0]
    输出: [0]
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

// 双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        for (; right < nums.size(); right++) {
            if (nums[right] != 0) {
                nums[left] = nums[right];
                left++;
            }
        }
        for (int i = left + 1; i < nums.size(); i++) nums[left] = 0;
        
    }
};