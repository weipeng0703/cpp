/*
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数。
示例 1:
    输入: [7,5,6,4]
    输出: 5
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
using namespace std; 

// 暴力
// 存在测试用例超时
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1)
        {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                if (nums[i] > nums[j])
                {
                    ++count;
                }
                
            }
            
        }
        return count;
    }
};

// 归并排序的回溯法
class Solution {
public:
    int mergeSort(int left, int right,vector<int>& nums, vector<int>& temp){
        // 终止条件
        if(left >= right) return 0;
        // 递归划分
        int mid = left + (right - left) / 2;
        int res = mergeSort(left, mid ,nums, temp) + mergeSort(mid + 1,right ,nums, temp);
        // 合并
        int i = left, j = mid + 1;
        for (int k = left; k <= right; k++)
        {
            temp[k] = nums[k];
        }
        for (int k = left; k <= right; k++)
        {
            if (i == mid + 1)
            {
                nums[k] = temp[j++];
            }
            else if (j == right + 1 || temp[i] <= temp[j])
            {
                nums[k] = temp[i++];
            }
            else
            {
                nums[k] = temp[j++];
                res += mid - i + 1;
            }
        }
        return res;
    }
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
        return mergeSort(0, nums.size() -1 ,nums, temp);
    }
};