/*
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。


示例 1:

输入: [3,2,1,5,6,4] 和 k = 2
输出: 5

示例 2:

输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

// 方法一：直接sort()排序
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int size = nums.size();
        if(size == 1 && k == 1)
        {
            return nums[0];
        }
        else if(size == 1 && k > 1)
        {
            return -1;
        }
        sort(nums.begin(), nums.end());
        return nums[size - k];
    }
};

