/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-12 20:52:49
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-12 21:27:58
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 15:36:10
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 16:17:20
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

/*
力扣T-977. 有序数组的平方
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
示例 1：
    输入：nums = [-4,-1,0,3,10]
    输出：[0,1,9,16,100]
    解释：平方后，数组变为 [16,1,0,9,100]
    排序后，数组变为 [0,1,9,16,100]
示例 2：
    输入：nums = [-7,-3,2,3,11]
    输出：[4,9,9,49,121]
*/

// 1-暴力后排序
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        for (int num : nums) ans.push_back(num * num);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// 2-双指针
// left与right分别从nums的前后往中间靠，将二者的平方中大的数插入答案数组
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int last = nums.size() - 1;
        for (int left = 0, right = nums.size() - 1; left <= right; ) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[last] = nums[right] * nums[right];
                right--;
                last--;
            } else {
                ans[last] = nums[left] * nums[left];
                left++;
                last--;
            }
        }
        return ans;
    }
};

// 如果要求数组中没有重复的平方数 eg. [-3,-1,0,1,2,4] -> [0,1,4,9,16]
// 思路与上面双指针的思路一样，只是在nums[left] == nums[right]的时候，任选一个的平方数加入结果数组，
// 然后双指针同时向里移动。但是要注意数组中数据个数与答案数组个数的影响
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int last = nums.size() - 1;
        for (int left = 0, right = nums.size() - 1; left <= right; ) {
            if (nums[left] * nums[left] < nums[right] * nums[right]) {
                ans[last] = nums[right] * nums[right];
                right--;
                last--;
            } else if (nums[left] * nums[left] > nums[right] * nums[right]){
                ans[last] = nums[left] * nums[left];
                left++;
                last--;
            } else if (nums[left] * nums[left] == nums[right] * nums[right]){
                ans[last] = nums[left] * nums[left];
                left++;
                right--;
                last--;
            }
        }
        return ans;
    }
};