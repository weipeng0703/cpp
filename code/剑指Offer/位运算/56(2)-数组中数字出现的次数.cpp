/*
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：
    输入：nums = [3,4,3,3]
    输出：4
示例 2：
    输入：nums = [9,1,7,9,7,9,7]
    输出：1
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 
// 1.暴力
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        //只有三种情况
        if (nums[0] != nums[1]) return nums[0];
        if (nums[n - 2] != nums[n - 1]) return nums[n - 1];
        for (int i = 1;i < n;i++){
            if (nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        }        
        return 0;
    }
};
// 2.暴力的简洁写法
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        for(i = 0; i < nums.size() - 1; )
        {
            if(nums[i] != nums[i + 1])break;
            i = i + 3;
        }
        return nums[i];
    }
};
// 3.哈希表
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         unordered_map<int, int> dict;
//         for (auto &i : nums) ++dict[i];
//         for (auto auto[K, v] : dict) 
//             if (v == 1) return k;
//         return 0;
//     }
// };
// 4.位运算(有限状态自动机)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0, sub = 0; i < 32; ++i, sub = 0) {
            for (auto &n : nums) sub += ((n >> i) & 1);
            if (sub % 3) res |= (1 << i);
        }
        return res;
    }
};
