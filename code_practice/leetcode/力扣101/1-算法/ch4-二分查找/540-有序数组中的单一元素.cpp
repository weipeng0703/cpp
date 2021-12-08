/*
给你一个仅由整数组成的有序数组，其中每个元素都会出现两次，唯有一个数只会出现一次。
请你找出并返回只出现一次的那个数。
你设计的解决方案必须满足 O(log n) 时间复杂度和 O(1) 空间复杂度。

示例 1:

输入: nums = [1,1,2,3,3,4,4,8,8]
输出: 2

示例 2:

输入: nums =  [3,3,7,7,10,11,11]
输出: 10

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
using namespace std;

// 方法一：暴力，如果某个数字跟之前数字不一样输出它，但是其复杂度分别为n和1
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        
        // 从第一个元素开始，我们检查每个第二个元素是否与当前元素相同。 如果不同，说明该元素是单个元素。
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        
        // 如果到达最后一个元素，则它为单一元素。
        return nums.back();
    }
};


// 方法二：使用unordered_map存储数据及其出现的次数，返回次数为1的数
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) 
            return nums[0];
        unordered_map<int, int> counter;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            counter[nums[i]]++;
        }
        for (auto& kv : counter) {
            if (kv.second == 1) {
                ans = kv.first;
                break;
            }
        }
        return ans;
    }
};

// 方法三：二分查找
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mid % 2 == 1) 
                mid--;

            // 如果中间数和他后面的数相同，说明单一数在中间数右边
            if (nums[mid] == nums[mid + 1]) {
                low = mid + 2;
            } 
            // 否则，单一数即为中间数或在中间数左边
            else 
            {
                high = mid;
            }
        }
        // 循环结束后唯一的数字即为单一数
        return nums[low];
    }
};
