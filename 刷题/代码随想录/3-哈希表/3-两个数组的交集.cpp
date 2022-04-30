/*
力扣349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。

示例 1：
    输入：nums1 = [1,2,2,1], nums2 = [2,2]
    输出：[2]
示例 2：
    输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
    输出：[9,4]
    解释：[4,9] 也是可通过的
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
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1.自己写的哈希表
class Solution {
public:
    bool isExist(vector<int>& a, int b) {
        for (auto ele : a) if (ele == b) return true;
        return false;
    }
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int n = max(nums1.size(), nums2.size());
        vector<int> temp(1000, 0);

        for (int i = 0; i < nums1.size(); i++) ++temp[nums1[i] - 0];
        
        for (int i = 0; i < nums2.size(); i++)
        {
            if (temp[nums2[i] - 0] != 0)
            {
                bool flag = isExist(ans, nums2[i]);
                if (flag == false) ans.push_back(nums2[i]);
            }
        }
        return ans;
    }
};
// 2.哈希表优化（但是相应的时间效率和空间效率会增加）
// 结果数组使用unordered_set可以直接去重
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> res; // 存放结果
        unordered_set<int> temp(nums1.begin(), nums1.end());
        for (int num : nums2) {
            // 如果nums2的元素在temp里出现过，说明存在交集，将其加入结果数组
            if (temp.find(num) != temp.end()) res.insert(num);
        }
        return vector<int>(res.begin(), res.end());
    }
};