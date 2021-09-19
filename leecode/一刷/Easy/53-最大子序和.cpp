/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），
返回其最大和。

示例 1：
    输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
    输出：6
    解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：
    输入：nums = [1]
    输出：1
示例 3：
    输入：nums = [0]
    输出：0
示例 4：
    输入：nums = [-1]
    输出：-1
示例 5：
    输入：nums = [-100000]
    输出：-100000
*/
#include<vector>
using namespace std;

// 1.贪心算法
// 思想：遍历数组，若遍历到数据nums[i]之前的数据和<0，
// 则丢弃之前的所有数据（但是保留之前算过的最大何值）
// 这个解答还稍微有些问题
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_sum = nums[0];
        int maxSum = nums[0];

        if(nums.size() == 1)
        {
            return nums[0];
        }
            
        for (int i = 0; i < nums.size(); i++)
        {
            current_sum = max(nums[i], current_sum + nums[i]);
            maxSum = max(maxSum, current_sum);
        }
        return maxSum;
    }
};

// 2.动态规划
// 思想：若前一个元素大于0，则将其加到当前元素上

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
        int MaxSum = INT_MIN;
        //dp[i]表示nums中以nums[i]结尾的最大子序和
        vector<int> v(nums.size());
        v[0] = nums[0];
        MaxSum = v[0];
        for (int i = 1; i < nums.Size(); i++)
        {
            v[i] = max(v[i - 1] + nums[i], nums[i]);
            MaxSum = max(MaxSum, v[i]);
        }

        return MaxSum;
    }
};





// 3.暴力解法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 类似寻找最大最小值的题目，
        // 初始值一定要定义成理论上的最小最大值
        int max = INT_MIN;
        for (int i = 0; i < sums.size(); i++)
        {
            int sum = 0;   // 在每次开始执行序列相加前将中间结果sum置0
            for (int j = i; j < sums.size(); j++)
            {
                sum += nums[j];
                if (sum > max)    // 若中间结果小于0则一直累加
                {
                    max = sum;
                }
            }
        }

        return max;
    }
};
