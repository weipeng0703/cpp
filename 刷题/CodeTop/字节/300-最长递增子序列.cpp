/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 20:05:33
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-05 20:40:16
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

/*
力扣T-300. 最长递增子序列
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

注意区分——子序列可以是不连续的，但是子数组/子字符串一定要是连续的

示例 1：
    输入：nums = [10,9,2,5,3,7,101,18]
    输出：4
    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：
    输入：nums = [0,1,0,3,2,3]
    输出：4
示例 3：
    输入：nums = [7,7,7,7,7,7,7]
    输出：1
*/

// 1-dp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};

// 2.dp(贪心) + 二分查找 (可以将时间复杂度由上面的N平方降为N*logN)
//
// dp[i]表示存储长度为 i+1 的最长递增子序列的 最后一个数字
// 遍历每一个位置 i，如果其对应的数字大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
// 如果发现这个数字在 dp 数组中比数字 a 大、比数字 b 小，则将 b 更新为此数字，使得之后构成递增序列的可能性增大(贪心)。
// 以这种方式维护的 dp 数组永远是递增的，因此可以用二分查找加速搜索。

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp;
        dp.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            // 如果nums[i]大于 dp 数组中所有数字的值，那么把它放在 dp 数组尾部，表示最长递增子序列长度加 1；
            if (dp.back() < nums[i])  dp.push_back(nums[i]);
            // 否则，将dp数组中 第一个大于等于nums[i] 的数更新为num[1]，使得之后构成递增序列的可能性增大(贪心)。
            else {
                // 寻找目前的dp数组中第一个>=nums[i]的数
                int left = 0, right = dp.size() - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (dp[mid] >= nums[i]) right = mid - 1;
                    else left = mid + 1;
                }
                dp[left] = nums[i];
            }
        }
        return dp.size();
    }
};

// 使用lower_bound作为封装好的二分查找
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

