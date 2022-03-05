/*
输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
要求时间复杂度为O(n)。
示例 1:
    输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出: 6
    解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// （动态规划）
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        int ans = nums[0];
        dp[0] = nums[0];
        // 对于一个元素，只有取和不取两种状态
        // 如果取：则 dp[i] = dp[i-1] + nums[i]
        // 如果不取：则 dp[i] = nums[i]（相当于从这个元素作为子区间的新起点，重新算起）
        // 所以 dp[i] = Math.max(dp[i-1] + nums[i],nums[i])
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 为什么c++解法经常在循环中使用&x，而且也没改变x的内容？

// 用&可以直接使用变量值，如果不用&的话运行时会复制一遍变量再使用。
// 用&可以直接使用变量而不需要复制，同时加上const的限制可以保证变量在循环中不改变。
// 特别是对于自定义的变量类型循环中使用&特别有用，否则将复制自定义的变量类型进内存中使用。