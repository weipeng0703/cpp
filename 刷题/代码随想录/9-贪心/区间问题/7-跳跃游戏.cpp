/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-30 09:35:42
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-30 11:09:13
 */
/*
力扣55. 跳跃游戏
给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。
示例 1:
    输入：nums = [2,3,1,1,4]
    输出：true
    解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
示例 2:
    输入：nums = [3,2,1,0,4]
    输出：false
    解释：无论怎样，总会到达下标为 3 的位置。但该下标的最大跳跃长度是 0 ， 所以永远不可能到达最后一个下标。

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

// 1. 贪心法
// 不需要纠结在每个位置要跳几步，只需要判断某位置的跳跃可达范围(范围内都可以到达)，
// 直到判断到终点是否在可达范围内即可
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        // field表示截至当前能跳跃的最远距离
        int field = 0;
        // i <= field表示在当前最远距离内的地方再跳跃一段距离
        for (int i = 0; i <= field; i++) {
            // 更新最远距离
            field = max(i + nums[i], field);
            // 若最远距离的下标 > 终点位置表示成功
            if (nums.size() - 1 <= field) return true;
        }
        return false;
    }
};