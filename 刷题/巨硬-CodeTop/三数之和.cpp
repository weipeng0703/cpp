/*
力扣15.三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

示例 1：
    输入：nums = [-1,0,1,2,-1,-4]
    输出：[[-1,-1,2],[-1,0,1]]
示例 2：
    输入：nums = []
    输出：[]
示例 3：
    输入：nums = [0]
    输出：[]
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3)
        {
            return ans;
        }

        for (int i = 0; i < n; i++)
        {
            // 不需要新建一个数组保存结果v
            // ector<int> temp;

            // nums[j]需要和上一次枚举的数不相同
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int k = n - 1;
            int target = -nums[i];

            for (int j = i + 1; j < n; j++)
            {
                // nums[k]需要和上一次枚举的数不相同
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                 while (j < k && nums[j] + nums[k] > target) {
                    --k;
                }
                if(j == k)
                {
                    break;
                }
                if(nums[j] + nums[k] == target)
                {
                    // 不需要再额外开辟空间记录答案
                    ans.push_back({nums[i], nums[j], nums[k]});    
                }
                }
            }
            
        return ans;
    }
};