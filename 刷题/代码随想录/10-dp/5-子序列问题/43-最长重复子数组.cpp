/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-20 10:21:01
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-20 14:09:25
 */
/*
力扣718. 最长重复子数组
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

示例 1：
    输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
    输出：3
    解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：
    输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
    输出：5
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

// 注意：子数组跟子序列不一样
// 子序列不保证序列是连续的，而子数组要保证是连续的子序列
// 1.dp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};