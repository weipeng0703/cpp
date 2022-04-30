/*
力扣27. 移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

示例 1：
    输入：nums = [3,2,2,3], val = 3
    输出：2, nums = [2,2]
示例 2：
    输入：nums = [0,1,2,2,3,0,4,2], val = 2
    输出：5, nums = [0,1,4,0,3]
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
// 注意：数组的元素在内存地址中是连续的，不能单独删除数组中的某个元素，只能覆盖。

// 直观反应使用erase方法抹除数，但是复杂度为O(n平方)太高

// 1.双指针法
// 利用右指针遍历数组数据，碰到等于val的数略过；
// 右指针不等于val时，令左指右移指向当前右指针指向的数，并且nums[left] = nums[right]覆盖掉等于val的数
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 左指针代表最后保留下的数组中元素的指向
        int left = 0;
        // 右指针遍历nums中的数据
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] != val){
                nums[left] = nums[right];
                left++;
            }
        }
        return left;
    }
};
//         for (int i = 0; i < left; i++){
//             cout << nums[i] << " ";
//         }
// 时间复杂度：$O(n)$
// 空间复杂度：$O(1)$
