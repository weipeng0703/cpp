/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-30 22:30:46
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-30 22:59:32
 */
/*
力扣T-33. 搜索旋转排序数组
整数数组 nums 按升序排列，数组中的值 互不相同 。
在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，
使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。
例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。
给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。
你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
    输入：nums = [4,5,6,7,0,1,2], target = 0
    输出：4
示例 2：
    输入：nums = [4,5,6,7,0,1,2], target = 3
    输出：-1
示例 3：
    输入：nums = [1], target = 0
    输出：-1
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

// 1-遍历整个数组寻找
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

// 2-二分查找
// 将数组一分为二，其中一定有一个是有序的，另一个可能是有序，也可能是部分有序。
// 此时有序部分用二分法查找。无序部分再一分为二，其中一个一定有序，另一个可能有序，可能无序。就这样循环. 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return -1;
        if (n == 1) return nums[0] == target? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (target == nums[mid]) return mid;
            // 有序的部分直接用二分查找
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) r = mid - 1;
                else l = mid + 1;
            } else {    // 无序部分继续一分为二（有序部分和无序部分）
                if (nums[mid] <= target && target <= nums[n - 1]) l = mid + 1;
                else r = mid - 1;
            }
        }
        return -1;
    }
};