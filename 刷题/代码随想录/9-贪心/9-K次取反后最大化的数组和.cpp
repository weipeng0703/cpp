/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-01 09:40:37
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-01 10:47:26
 */
/*
力扣1005. K 次取反后最大化的数组和
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：
选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。
以这种方式修改数组后，返回数组 可能的最大和 。
 
示例 1:
    输入：nums = [4,2,3], k = 1
    输出：5
    解释：选择下标 1 ，nums 变为 [4,-2,3] 。
示例 2:
    输入：nums = [3,-1,0,2], k = 3
    输出：6
    解释：选择下标 (1, 2, 2) ，nums 变为 [3,1,0,2] 。
示例 3：
    输入：nums = [2,-3,-1,5,-4], k = 2
    输出：13
    解释：选择下标 (1, 4) ，nums 变为 [2,3,-1,5,4] 。
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
// 1.将数组按绝对值大小排序
// 2.将数组中的负数变为正，每变一个数k--
// 3.若k>0,将剩余的变化都施加到数组最后一个数上（这样使得最后数组的所有数字总和一定是最大）
class Solution {
public:
    // 按照绝对值排序
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        int ans = 0;
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {
                nums[i] *= -1;
                k--;
            }
        }
        // while (k > 0) {
        //     nums[nums.size() - 1] *= -1;
        //     k--;
        // }
        // 最后如果K仍然大于0，可以直接判断k的奇偶：
        // 如果是奇数，直接将nums最后一个数变号
        // 若k是偶数，最后一个数不变即可
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        for (int ele : nums) ans += ele;
        return ans;
    }
};