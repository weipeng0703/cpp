/*
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。

示例 1：

    输入：nums = [4,3,2,7,8,2,3,1]
    输出：[5,6]

示例 2：

    输入：nums = [1,1]
    输出：[2]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:暴力解法，会超时
class Solution {
public:
    bool findit(vector<int>& nums, int num)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == num)
            {
                return true;
            }
            
        }
        return false;
    }
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();

        vector<int> res;

        for (int i = 1; i <= size; i++)
        {
            bool flag = findit(nums, i);
            if (flag == false)
            {
                res.push_back(i);
            }
            
        }
        sort(res.begin(), res.end());
        return res;
    }
};

// 方法二:原地修改数组，用正负表示数是否出现过（数组可以蕴含很多数组内数字之外的信息）
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (const num : nums)
        {
            int pos = ans(num) - 1;
            // 用数组中数字的正负表示该位置是否出现过
            // 比如：num[pos] < 0,说明pos这个数字是在数组中出现过的
            if (num[pos] > 0)
            {
                num[pos] = -num[pos];
            }
        }
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                // 因为是按照i从小到大的顺序进行的，所以最后的数组甚至都不需要排序
                ans.push_back(i + 1);
            }
            
        }
        return res;

    }
};