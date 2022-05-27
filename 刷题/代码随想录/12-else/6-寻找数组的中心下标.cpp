/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-27 09:54:20
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-27 10:39:45
 */
/*
力扣724. 寻找数组的中心下标
给你一个整数数组 nums ，请计算数组的 中心下标 。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。

示例 1：
    输入：nums = [1, 7, 3, 6, 5, 6]
    输出：3
    解释：
    中心下标是 3 。
    左侧数之和 sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11 ，
    右侧数之和 sum = nums[4] + nums[5] = 5 + 6 = 11 ，二者相等。
示例 2：
    输入：nums = [1, 2, 3]
    输出：-1
    解释：
    数组中不存在满足此条件的中心下标。
示例 3：
    输入：nums = [2, 1, -1]
    输出：0
    解释：
    中心下标是 0 。
    左侧数之和 sum = 0 ，（下标 0 左侧不存在元素），
    右侧数之和 sum = nums[1] + nums[2] = 1 + -1 = 0 。
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

// 注：该题要注意遍历的方式，不能一趟趟循环遍历求左边和与右边和;
// 而要求出左边和，用sum减去它求得右边和

// 1-遍历一遍求总和，第二遍求每个索引左边和与右边和
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int ele : nums) sum += ele;
        // 用这两个变量记忆左边和与右边和
        int leftSum = 0, rightSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 左右两边和都加上一个nums[i]
            leftSum += nums[i];
            rightSum = sum - leftSum + nums[i];
            if (leftSum == rightSum) return i;
        }
        return -1;
    }
};