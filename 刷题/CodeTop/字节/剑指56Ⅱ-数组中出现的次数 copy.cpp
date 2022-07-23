/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 14:19:32
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 14:32:50
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
#include<queue>
using namespace std; 
/*
（上一题）力扣-剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

（该题）剑指 Offer 56 - II. 数组中数字出现的次数 II
在一个数组 nums 中除一个数字只出现一次之外，其他数字都出现了三次。请找出那个只出现一次的数字。

示例 1：
    输入：nums = [3,4,3,3]
    输出：4
示例 2：
    输入：nums = [9,1,7,9,7,9,7]
    输出：1
*/ 
// 1-哈希表
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> umap;
        int ans = 0;
        for (int ele : nums) umap[ele]++;
        for (auto& kv : umap) {
            if (kv.second == 1) ans = kv.first;
        }
        return ans;
    }
};
// 2-位运算(有限状态自动机)
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
