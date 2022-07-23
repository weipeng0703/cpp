/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 09:40:58
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 10:02:04
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
#include<queue>
using namespace std; 
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 09:16:41
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 09:28:52
 */
/*
力扣-剑指 Offer 39. 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
你可以假设数组是非空的，并且给定的数组总是存在多数元素。

示例 1：
    输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
    输出: 2
*/ 

// 1-直接数组排序，超过一半一定是数组中间的数
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};
// 2.最优解——Boyer-Moore 投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 假设众数为x
        int x = 0, votes = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 本题确定有众数，若题目没说确定有众数，要加入一段验证代码
        // # 验证 x 是否为众数
        // for num in nums:
        //     if num == x: count += 1
        // return x if count > len(nums) / 2 else 0 # 当无众数时返回 0
        return x;
    }
};
// 时间复杂度：O(n)。遍历一遍数组
// 空间复杂度：O(1)。没有用到额外空间