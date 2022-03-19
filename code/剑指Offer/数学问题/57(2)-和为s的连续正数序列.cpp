/*
输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

示例 1：
    输入：target = 9
    输出：[[2,3,4],[4,5]]
示例 2:
    输入：target = 15
    输出：[[1,2,3,4,5],[4,5,6],[7,8]]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
// #include<unordered_map>
using namespace std; 

// 1.暴力遍历
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if (target <= 1)
        {
            return ans;
        }
        vector<int> temp;
        int sum = 0;
        for (int i = 1; i <= (target - 1) / 2; i++)
        {
            for (int j = i; ; j++)
            {
                sum += j;
                if (sum > target)
                {
                    sum = 0;
                    break;
                }
                else if (sum == target)
                {
                    temp.clear();
                    for (int k = i; k <= j; k++)
                    {
                        temp.push_back(k);
                    }
                    ans.push_back(temp);
                    sum = 0;
                    break;
                }
                
            }
            
        }
        return ans;
    }
};
// 时间复杂度：
// 空间复杂度：O(1)。没有用到额外空间

// 2.求连续区间问题，应该立刻有双指针的思路
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> ans;
        if (target <= 1)
        {
            return ans;
        }
        vector<int> temp;
        
        for (int left = 1, right = 2; left < right; )
        {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target)
            {
                for (int k = left; k <= right; k++)
                {
                    temp.push_back(k);
                }
                ans.push_back(temp);
                temp.clear();
                ++left;
            }
            else if (sum < target)
            {
                ++right;
            }
            else
            {
                ++left;
            }
        }
        return ans;
    }
};
// 时间复杂度：O(target):两个指针均单调不减，且移动范围均 <= target / 2
// 空间复杂度：O(1)。除了答案数组只需要常数空间存储变量