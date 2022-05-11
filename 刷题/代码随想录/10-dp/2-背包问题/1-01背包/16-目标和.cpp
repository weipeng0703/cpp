/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-10 22:01:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-11 09:44:39
 */
/*
力扣494. 目标和
给你一个整数数组 nums 和一个整数 target 。
向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：
    输入：nums = [1,1,1,1,1], target = 3
    输出：5
    解释：一共有 5 种方法让最终目标和为 3 。
    -1 + 1 + 1 + 1 + 1 = 3
    +1 - 1 + 1 + 1 + 1 = 3
    +1 + 1 - 1 + 1 + 1 = 3
    +1 + 1 + 1 - 1 + 1 = 3
    +1 + 1 + 1 + 1 - 1 = 3
示例 2：
    输入：nums = [1], target = 1
    输出：1
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

// 2.dp-01背包问题(转化过程见图)
// 注意：在求装满背包有几种方法的情况下，递推公式一般为：
// dp[j] += dp[j - nums[i]];
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int sum = 0;
        for (int ele : nums) sum += ele;
        // 两种无解情况剪枝
        if (abs(target) > sum) return 0;        // 无论nums数组如何组合都凑不出正/负target
        if ((sum + target) % 2 == 1) return 0;  // sum + target若为奇，除以2后肯定有小数，然而nums数组中均为整数

        int temp = (sum + target) / 2;
        vector<int> dp(temp + 1, 0);
        dp[0] = 1;      // 和为0，没有数放进去也是一种安排方式
        for (int i = 0; i < nums.size(); i++) {
            for (int j = temp; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[temp];
    }
};

// 1.回溯法(会超时)
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    void backtrack(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) ans.push_back(path);

        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            batrack(candidates, target, sum, i + 1);
            sum -= candidates[i];
            path.pop_back();
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        if (nums.size() == 0) return 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (target > sum) return 0;
        if ((target + sum) % 2) return 0;
        int bagSize = (target + sum) / 2;

        sort(nums.begin(), nums.end());
        backtrack(nums, bagSize, 0, 0);
        return ans.size();
    }
};
