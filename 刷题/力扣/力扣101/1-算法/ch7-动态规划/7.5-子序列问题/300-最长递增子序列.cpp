/*
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：
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
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.DP
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), max_length = 0;
        if (n <= 1)
        {
            return n;
        }
        // 注意这个地方dp数组初始化为1，因为数组nums中如果所有数字都相同，答案也该为1
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // max_length = max(max_length, dp[i]);
        }
        sort(dp.begin(), dp.end());
        return dp[n - 1];
        // return max_length;
    }
};