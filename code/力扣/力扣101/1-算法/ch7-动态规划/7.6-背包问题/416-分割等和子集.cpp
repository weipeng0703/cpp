/*
给你一个 只包含正整数 的 非空 数组 nums 。
请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 

示例 1：
    输入：nums = [1,5,11,5]
    输出：true
    解释：数组可以分割成 [1, 5, 5] 和 [11] 。
示例 2：
    输入：nums = [1,2,3,5]
    输出：false
    解释：数组不能分割成两个元素和相等的子集。
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
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
        {
            return false;
        }
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 == 1)
        {
            return false;
        }
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; i++)
        {
            // j可以看作背包的体积
            for (int j = 0; j <= target; j++)
            {
                if (nums[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];  
                }
            }
        }
        return dp[n][target];
    }
};