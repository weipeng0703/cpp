/*
同力扣T169
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
示例 1：
    输入: [1, 2, 3, 2, 2, 2, 5, 4, 2]
    输出: 2
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
using namespace std; 

// 1.sort()后求中间数字
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;
        return nums[n];
    }
};
// 时间复杂度：O(nlogn)。将数组排序的时间复杂度为 O(nlogn)。

// 空间复杂度：O(logn)。如果使用语言自带的排序算法，需要使用 O(logn) 的栈空间。
// 如果自己编写堆排序，则只需要使用 O(1) 的额外空间。

// 2.最优解——Boyer-Moore 投票算法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 假设众数为x
        int x = 0, votes = 0;
        for(int num : nums){
            if(votes == 0) x = num;
            votes += num == x ? 1 : -1;
        }
        // 本题确定有众数，若题目没说确定有众数，要加入一段验证代码
        // # 验证 x 是否为众数
        // for num in nums:
        //     if num == x: count += 1
        // return x if count > len(nums) / 2 else 0 # 当无众数时返回 0
        return x;
    }
};
// 时间复杂度：O(n)。遍历一遍数组

// 空间复杂度：O(1)。没有用到额外空间