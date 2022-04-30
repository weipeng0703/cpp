/*
符合下列属性的数组 arr 称为 山峰数组（山脉数组） ：

arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给定由整数组成的山峰数组 arr ，
返回任何满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i ，
即山峰顶部。

示例 1:
    输入：arr = [0,1,0]
    输出：1
示例 2:
    输入：arr = [1,3,5,4,2]
    输出：2
示例三：
    输入：arr = [0,10,5,2]
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
using namespace std; 
// 1.暴力解法
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > arr[i - 1] && arr[i] < arr[i + 1])
            {
                ans = i;
            }
            
        }
        return ans;
    }
};
// 2.二分查找
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 1, j = arr.size() - 2;
        int ans= 0;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (arr[mid] > arr[mid + 1])
            {
                ans = mid;
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        return ans;
    }
};