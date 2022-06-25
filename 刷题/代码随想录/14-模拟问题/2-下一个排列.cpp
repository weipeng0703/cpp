/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-25 21:29:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-25 22:02:44
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-25 21:16:07
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-25 21:29:15
 */
/*
力扣T31. 下一个排列
整数数组的一个 排列  就是将其所有成员以序列或线性顺序排列。

例如，arr = [1,2,3] ，以下这些都可以视作 arr 的排列：[1,2,3]、[1,3,2]、[3,1,2]、[2,3,1] 。
整数数组的 下一个排列 是指其整数的下一个字典序更大的排列。
更正式地，如果数组的所有排列根据其字典顺序从小到大排列在一个容器中，那么数组的 下一个排列 
就是在这个有序容器中排在它后面的那个排列。
如果不存在下一个更大的排列，那么这个数组必须重排为字典序最小的排列（即，其元素按升序排列）。

例如，arr = [1,2,3] 的下一个排列是 [1,3,2] 。
类似地，arr = [2,3,1] 的下一个排列是 [3,1,2] 。
而 arr = [3,2,1] 的下一个排列是 [1,2,3] ，因为 [3,2,1] 不存在一个字典序更大的排列。
给你一个整数数组 nums ，找出 nums 的下一个排列。

必须 原地 修改，只允许使用额外常数空间。

示例 1：
    输入：nums = [1,2,3]
    输出：[1,3,2]
示例 2：
    输入：nums = [3,2,1]
    输出：[1,2,3]
示例 3：
    输入：nums = [1,1,5]
    输出：[1,5,1]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1. 进阶版两趟扫描
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;
        for (int i = nums.size() - 1; i >= 0; i--) {
            // 在nums[i]后面寻找比其大的nums[j]
            for (int j =  nums.size() - 1; j > i; j--) {
                if (nums[i] < nums[j]) {
                    swap(nums[j], nums[i]);
                    reverse(nums.begin() + i + 1, nums.end());
                    return;
                }
            }
        }
        // 如果全部遍历完没有满足要求的，证明当前排序为最大排序，直接将数组反转即可
        reverse(nums.begin(), nums.end());
    }
};