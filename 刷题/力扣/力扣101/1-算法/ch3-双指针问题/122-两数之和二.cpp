/*
给定一个已按照 非递减顺序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target 。

函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 1 开始计数 ，
所以答案数组应当满足 1 <= answer[0] < answer[1] <= numbers.length 。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。

输入：numbers = [2,3,4], target = 6
输出：[1,3]

输入：numbers = [-1,0], target = -1
输出：[1,2]
*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;

// 一遍过
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int start = 0, end = (size - 1);        // 注意end范围
        
        vector<int> res;

        while (start != end)
        {
            if (numbers[start] + numbers[end] == target)
            {
                res.push_back(start + 1);
                res.push_back(end + 1);
                break;
            }
            else if (numbers[start] + numbers[end] < target)
            {
                start++;
            }
            else if (numbers[start] + numbers[end] > target)
            {
                end--;    // 注意start与end变化的方向
            }
            
            
        }
        return res;
        
    }
};

// 简洁版本
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int start = 0, end = (size - 1);

        while (start != end)
        {
            int sum = numbers[start] + numbers[end];
            if (sum == target)
            {
                break;
            }
            else if (sum < target)
            {
                start++;
            }
            else if (sum > target)
            {
                end--;
            }
            
        }
        return vector<int> {start + 1, end + 1};
        
    }
};

