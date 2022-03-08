/*
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
示例：
    输入：nums = [1,2,3,4]
    输出：[1,3,2,4] 
    注：[3,1,2,4] 也是正确的答案之一。
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
#include<unordered_map>
// #include<algorithm>
using namespace std; 
// 1.暴力遍历数组放到两个奇偶数组中再将二者合并
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> jishu;
        vector<int> oushu;
        vector<int> res;
        for (auto ele : nums)
        {
            if (ele % 2 == 0)
            {
                oushu.push_back(ele);
            }
            else
            {
                jishu.push_back(ele);
            }
        }
        for (auto ele : jishu)
        {
            res.push_back(ele);
        }
        for (auto ele : oushu)
        {
            res.push_back(ele);
        }
        return res;
    }
};
// 2.双指针
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0)
        {
            return res; 
        }
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] % 2 == 1 && nums[right] % 2 == 0)
            {
                ++left;
                --right;
            }
            else if (nums[left] % 2 == 0 && nums[right] % 2 == 1)
            {
                swap(nums[left], nums[right]);
                ++left;
                --right;
            }
            else if (nums[left] % 2 == 0 && nums[right] % 2 == 0)
            {
                --right;
            }
            else if (nums[left] % 2 == 1 && nums[right] % 2 == 1)
            {
                --left;
            }
        }
        return nums;
    }
};