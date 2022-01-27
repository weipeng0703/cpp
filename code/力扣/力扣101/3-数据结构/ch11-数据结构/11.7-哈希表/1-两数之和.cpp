/*
给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：

输入：nums = [3,3], target = 6
输出：[0,1]
*/

#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;


// solution 1——双循环暴力解法，时间复杂度O(n²)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < sizeof(nums); i++)
        {
            for (int j = i + 1; j < sizeof(nums); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    return {i, j};
                }
                
            }
            
        } 
        return {};
    }

};

// solution 2——使用map哈希表解决
// 思路：
// 由于哈希查找的时间复杂度为 O(1)，所以可以利用哈希容器 map 降低时间复杂度
// 遍历数组 nums，i 为当前下标，每个值都判断map中是否存在 target-nums[i] 的 key 值
// 如果存在则找到了两个值，
// 如果不存在则将当前的 (nums[i],i) 存入 map 中，继续遍历直到找到为止
// 如果最终都没有结果则抛出异常


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        for(int i =0; i< nums.size(); i++)
        {
            map<int, int>::iterator it = m.find(target - nums[i]);
            if(it != m.end())
            {
                return {it->second, i};
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }

};

// 哈希表另一种写法
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> temp;
        vector<int> res;

        for (int i = 0; i < nums.size(); i++)
        {
            auto pos = temp.find(target - nums[i]);
            if (pos == temp.end())
            {
                temp.insert(pair<int, int>(nums[i], i));
            }
            else
            {
                res.push_back(pos->second);
                res.push_back(i);
                break;
            }
            
        }
        return res;
    }
};