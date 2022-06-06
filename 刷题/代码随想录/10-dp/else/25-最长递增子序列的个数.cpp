/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-06 09:01:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-06 09:56:01
 */
/*
力扣673. 最长递增子序列的个数
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。
注意 这个数列必须是 严格 递增的。

示例 1:
    输入: [1,3,5,4,7]
    输出: 2
    解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:
    输入: [2,2,2,2,2]
    输出: 5
    解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1-dp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // 包括i之前的最长递增子序列的长度
        vector<int> dp(nums.size(), 1);
        // 以nums[i]结尾的字符串最长递增子序列的个数
        vector<int> count(nums.size(), 1);
        int maxCount = 0;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[j] + 1 == dp[i]) count[i] += count[j];
                }
                // 记录最长递增子序列的长度
                if (dp[i] > maxCount) maxCount = dp[i];
            }
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 如果以nums[i]为结尾是最长递增子序列的话，最终结果加上个数
            if (maxCount == dp[i]) ans += count[i];
        }
        return ans;
    }
};