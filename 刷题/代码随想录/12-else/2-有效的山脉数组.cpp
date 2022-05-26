/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-26 10:55:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-26 11:29:12
 */

/*
力扣941. 有效的山脉数组
给定一个整数数组 arr，如果它是有效的山脉数组就返回 true，否则返回 false。
让我们回顾一下，如果 arr 满足下述条件，那么它是一个山脉数组：
    arr.length >= 3
    在 0 < i < arr.length - 1 条件下，存在 i 使得：
    arr[0] < arr[1] < ... arr[i-1] < arr[i]
    arr[i] > arr[i+1] > ... > arr[arr.length - 1]
示例 1：
    输入：arr = [2,1]
    输出：false
示例 2：
    输入：arr = [3,5,5]
    输出：false
示例 3：
    输入：arr = [0,3,2,1]
    输出：true
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
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() <= 2) return false;
        int left = 0, right = arr.size() - 1;
        while (left + 1 < arr.size() && arr[left] < arr[left + 1]) left++;
        while (right - 1 >= 0 && arr[right] < arr[right - 1]) right--;
        // if (left != 0 && right != arr.size() - 1 && left == right) return true;
        if ((left > 0 && left < arr.size() -1 ) && (right > 0 && right < arr.size() - 1) && left == right) return true;
        return false;
    }
};