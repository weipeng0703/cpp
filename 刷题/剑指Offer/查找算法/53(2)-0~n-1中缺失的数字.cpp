/*
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。
在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。

示例 1:
    输入: [0,1,3]
    输出: 2
示例 2:
    输入: [0,1,2,3,4,5,6,7,9]
    输出: 8
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
// 1.暴力解法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums[0] == 1)
        {
            return 0;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
            
        }
        // 因为一定缺少一个数，排除以上情况缺少的就是最后一位数字
        return nums.size();
    }
};
// 2.对于顺序递增数组的查找搜索问题，优先考虑二分法
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] == mid)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return i;
    }
};