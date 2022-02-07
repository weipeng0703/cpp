/*
如果一个数列 至少有三个元素 ，并且任意两个相邻元素之差相同，则称该数列为等差数列。
例如，[1,3,5,7,9]、[7,7,7,7] 和 [3,-1,-5,-9] 都是等差数列。
给你一个整数数组 nums ，返回数组 nums 中所有为等差数组的 子数组 个数。
子数组 是数组中的一个连续序列。

示例 1：
    输入：nums = [1,2,3,4]
    输出：3
    解释：nums 中有三个子等差数组：[1, 2, 3]、[2, 3, 4] 和 [1,2,3,4] 自身。
示例 2：
    输入：nums = [1]
    输出：0
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
        {
            return 0;
        }
        vector<int> ans(n, 0);
        for (int i = 2; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                ans[i] = ans[i - 1] + 1;
            }   
        }
        // 第三个参数为累加的初值
        return accumulate(ans.begin(), ans.end(), 0);
    }
};