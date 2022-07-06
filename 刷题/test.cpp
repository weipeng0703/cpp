/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 09:17:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-06 10:05:30
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

// dp(贪心) + 二分查找 (时: N*logN)
//
// dp[i]表示存储长度为 i+1 的最长递增子序列的 最后一个数字
// 遍历每一个位置 i，如果其对应的数字大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
// 如果发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则将 b 更新为此数字，使得之后构成递增序列的可能性增大(贪心)。
// 以这种方式维护的 dp 数组永远是递增的，因此可以用二分查找加速搜索。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();

        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < len; ++i) {
            // 如果nums[i]大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
            if (dp.back() < nums[i])  dp.push_back(nums[i]);
            // 否则，将dp数组中 第一个大于等于nums[i] 的数更新为num[1]，使得之后构成递增序列的可能性增大(贪心)。
            else {
                // lower_bound利用二分查找在一个有序数组中查找 第一个大于或等于num[i]的数字（upper_bound）
                auto iter = std::lower_bound(dp.begin(), dp.end(), nums[i]);
                *iter = nums[i];
            }
        }
        return dp.size();
    }
};

// 寻找目前的dp数组中第一个>=nums[i]的数
int left = 0, right = len - 1, pos;
while (left <= right) {
    int mid = left + (right - left) / 2;


    
    if (dp[mid] >= nums[i]) right = mid - 1;
    else left = mid + 1;



    dp[left] = nums[i];
}
