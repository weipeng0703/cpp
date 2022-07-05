/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-01 11:10:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-01 11:35:41
 */
/*
力扣T-1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，
并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例1：
    输入：nums = [2,7,11,15], target = 9
    输出：[0,1]
    解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
    输入：nums = [3,2,4], target = 6
    输出：[1,2]
示例 3：
    输入：nums = [3,3], target = 6
    输出：[0,1]
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

// 1-暴力
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int temp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == temp) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};
// 2-哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            map<int, int>::iterator it = m.find(target - nums[i]);
            if(it != m.end()) return {it->second, i};
            m.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};

// 3-哈希表另一种写法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            auto pos = temp.find(target - nums[i]);
            if (pos == temp.end()) temp.insert(pair<int, int>(nums[i], i));
            else {
                res.push_back(pos->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};