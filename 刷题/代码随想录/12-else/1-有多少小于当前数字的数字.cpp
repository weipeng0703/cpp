/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-25 19:15:32
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-25 19:47:21
 */

/*
力扣1365. 有多少小于当前数字的数字
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。

示例 1:
    输入：nums = [8,1,2,2,3]
    输出：[4,0,1,1,3]
    解释： 
        对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
        对于 nums[1]=1 不存在比它小的数字。
        对于 nums[2]=2 存在一个比它小的数字：（1）。 
        对于 nums[3]=2 存在一个比它小的数字：（1）。 
        对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
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

// 1-暴力遍历
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] < nums[i]) ans[i]++;
            }
        }
        return ans;
    }
};

// 2-排序加哈希表
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        int hash[101];
        for (int i = vec.size() - 1; i >= 0; i--) {
            // 记录某个元素出现的位置(便是前面有几个小于他的数),
            // 从后向前遍历,用于处理重复元素的情况
            hash[vec[i]] = i;
        }
        for (int i = 0; i < vec.size(); i++) {
            vec[i] = hash[nums[i]];
        }
        return vec;
    }
};
