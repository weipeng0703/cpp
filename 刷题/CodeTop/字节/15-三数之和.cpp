/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-28 20:00:13
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-12 17:11:17
 */
/*
力扣T-15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？
请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
示例 2：
    输入：nums = []
    输出：[]
示例 3：
    输入：nums = [0]
    输出：[]
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

// 1-使用两数之和等于另一个数的相反数去求（配合剪枝过滤相同元素）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return ans;

        for (int i = 0; i < n; i++) {
            // 先过滤相同的第一个元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 从后向前加和
            int k = n - 1;
            int target = (-1) * nums[i];

            for (int j = i + 1; j < n; j++) {
                // nums[k]需要和上一次枚举的数不相同
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                while (k > j && nums[j] + nums[k] > target) --k;
                if(j == k) break;
                if(nums[j] + nums[k] == target) ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};

// 2.排序+双指针（配合剪枝过滤相同元素）
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3) return ans;

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int target = (-1) * nums[i];
            // 右指针
            int right = n - 1;
            // left为左指针
            for (int left = i + 1; left < n; left++) {
                // 需要和上一次枚举的数不相同
                if (left > i + 1 && nums[left] == nums[left - 1]) continue;
                while (left < right && nums[left] + nums[right] > target) --right;
                if(left == right) break;
                if(nums[left] + nums[right] == target) ans.push_back({nums[i], nums[left], nums[right]});
            }
        }
        return ans;
    }
};