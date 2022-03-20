/*
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
    输入：nums = [4,1,4,6]
    输出：[1,6] 或 [6,1]
示例 2：
    输入：nums = [1,2,10,4,1,4,3,3]
    输出：[2,10] 或 [10,2]
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
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n < 2){
            return ans;
        }
        sort(nums.begin(), nums.end());
        if(nums[0] != nums[1]){
            ans.push_back(nums[0]);
        }
        if(nums[n - 1] != nums[n - 2]){
            ans.push_back(nums[n - 1]);
        }
        for (int i = 1; i < nums.size() - 1; i++){
            if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
// 2.位运算
// 注意运算符的优先级：
// 对C++而言
// 9	==  !=	等于/不等于
// 10	&	按位与
// 11	^	按位异或
// 12	|	按位或
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        // 一定要初始化
        int temp = 0;
        // 求两个只出现一次的数字的异或值
        for (auto ele : nums)
        {
            temp ^= ele;
        }
        // 求temp出现1的最低位
        int div = 1;
        while ((div & temp) == 0)
        {
            div <<= 1;
        }
        int a = 0, b = 0;
        // 将nums分组
        // 每组中的异或值即为只出现一次的数字
        for (auto ele : nums)
        {
            if((ele & div)){
                a ^= ele;
            }
            else{
                b ^= ele;
            }
        }
        return vector<int>{a, b};
    }
};