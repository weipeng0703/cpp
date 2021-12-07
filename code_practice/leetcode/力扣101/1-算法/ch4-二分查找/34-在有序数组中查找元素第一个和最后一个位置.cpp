/*
给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。

进阶：

你可以设计并实现时间复杂度为 O(log n) 的算法解决此问题吗？

示例 1：

输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]
示例 2：

输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]
示例 3：

输入：nums = [], target = 0
输出：[-1,-1]
*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;


// 第一思路：暴力解法

// 第二思路：二分查找的时间复杂度为O(log n)，所以可以考虑二分查找

class Solution {
public:
    // 辅助函数：寻找下边界
    int findLower(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = left + (right - left)/2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    // 辅助函数：寻找上边界

    int findUpper(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = left + (right - left)/2;
            if (nums[mid] > target)     // 两个辅助函数的区别，因为找上边界是第一次出现的地方，所以包含等于。
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty())
        {
            return vector<int>{-1, -1};
        }
        int left = findLower(nums, target);
        int right = findUpper(nums, target) - 1;

        if (left == nums.size() || nums[left] != target)
        {
           return vector<int>{-1, -1};
        }
        return vector<int>{left, right};
    
    }
};

// 第三思路：直接使用stl库解决

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if (left == right)
            return vector<int>{-1, -1};
        else
            return vector<int>{(int)(left - nums.begin()), (int)(right - nums.begin() - 1)};
    }
};