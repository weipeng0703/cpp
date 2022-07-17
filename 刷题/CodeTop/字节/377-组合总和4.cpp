/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-17 20:41:26
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-17 22:11:18
 */
/*
力扣-377. 组合总和 Ⅳ
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。

示例 1：
    输入：nums = [1,2,3], target = 4
    输出：7
    解释：
    所有可能的组合为：
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)
    请注意，顺序不同的序列被视作不同的组合。
示例 2：
    输入：nums = [9], target = 3
    输出：0
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

// 1-回溯加剪枝会超时
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& vec, int targetSum, int sum) {
        if (sum > targetSum) return;
        if (sum == targetSum) ans.push_back(temp);
        for (int i = 0; i < vec.size() && sum + vec[i] <= targetSum; i++) {
            sum += vec[i];
            temp.push_back(vec[i]);
            backtrack(vec, targetSum, sum);
            temp.pop_back();
            sum -= vec[i];
        }
        return;
    }
    int combinationSum4(vector<int>& candidates, int target) {
        if (candidates.size() == 0) return 0;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return ans.size();
    }
};
// 2-dp完全背包
// 该题是求排列的数目
// 如果求组合数就是外层for循环遍历物品，内层for遍历背包。
// 如果求排列数就是外层for遍历背包，内层for循环遍历物品。
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        // 还有一种理解方式：如果数组中某个数nums[j]==target，则他自己也可以当作一种排列的方式
        dp[0] = 1;
        for (int i = 0; i <= target; i++) { // 遍历背包
            for (int j = 0; j < nums.size(); j++) { // 遍历物品
                // if (i - nums[j] >= 0) {
                // 后面是为了防止数据超过int可表示的最大范围
                if (i - nums[j] >= 0 && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }
        return dp[target];
    }
};
