/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-30 10:33:35
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-30 11:33:53
 */
/*
力扣45. 跳跃游戏 II
给你一个非负整数数组 nums ，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
 
示例 1:
    输入: nums = [2,3,1,1,4]
    输出: 2
    解释: 跳到最后一个位置的最小跳跃数是 2。
         从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置
示例 2:
    输入: nums = [2,3,0,1,4]
    输出: 2
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

// 1.贪心
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 0;
        // cur为当前跳跃的最远距离
        // next为下一步跳跃的最远距离
        int curField = 0, nextField = 0;
        for (int i = 0; i < nums.size(); i++) {
            nextField = max(nextField, nums[i] + i);    // 更新下一步跳跃的最远距离
            if (i == curField) {                        // 如果当前位于上一步求得的最远距离处
                if (curField != nums.size() - 1) {      // 如果没到终点
                    ans++;
                    curField = nextField;
                    if (nextField >= nums.size() - 1) break;
                } else break;    // 当前最远距离下标是终点，就不用ans++，直接结束
            }
        }
        return ans;
    }
};

// 2.方法一简化
// 针对于方法一的特殊情况，可以统一处理，
// 即：移动下标只要遇到当前覆盖最远距离的下标，直接步数加一，不考虑是不是终点的情况。
// 如要达到上面的效果，只要移动下标时令最大只能移动到nums.size - 2的地方就可以了。
//
// 因为当移动下标指向nums.size - 2时：
// 1.如果移动下标等于当前覆盖最大距离下标， 需要再走一步（即ans++），因为最后一步一定是可以到的终点。
// （题目假设总是可以到达数组的最后一个位置）
// 2.如果移动下标不等于当前覆盖最大距离下标，说明当前覆盖最远距离就可以直接达到终点了，不需要再走一步。
class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int ans = 0;
        // cur为当前跳跃的最远距离
        // next为下一步跳跃的最远距离
        int curField = 0, nextField = 0;
        for (int i = 0; i < nums.size() - 1; i++) {     // keypoint 
            nextField = max(nextField, nums[i] + i);    // 更新下一步跳跃的最远距离
            if (i == curField) {                        // 如果当前位于上一步求得的最远距离处
                    curField = nextField;
                    ans++;
                }
            }
        }
        return ans;
    }
};
