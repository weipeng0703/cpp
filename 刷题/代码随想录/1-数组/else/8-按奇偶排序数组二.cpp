/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-28 10:28:46
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-28 11:25:39
 */
/*
力扣922. 按奇偶排序数组 II
给定一个非负整数数组 nums，  nums 中一半整数是 奇数 ，一半整数是 偶数 。
对数组进行排序，以便当 nums[i] 为奇数时，i 也是 奇数 ；当 nums[i] 为偶数时， i 也是 偶数 。
你可以返回 任何满足上述条件的数组作为答案 。

示例 1：
    输入：nums = [4,2,5,7]
    输出：[4,5,2,7]
    解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
示例 2：
    输入：nums = [2,3]
    输出：[2,3]
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

// 1-开辟三个新数组
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> tempOdd;        // 存放全部奇数
        vector<int> tempEven;       // 存放全部偶数
        vector<int> ans(nums.size(), -1);
        int ansIndex = 0;
        // 将奇偶数分别放入奇偶数组
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) tempEven.push_back(nums[i]);
            else tempOdd.push_back(nums[i]);
        }
        // 将两个数组的数字放入ans
        for (int i = 0; i < tempEven.size(); i++) {
            ans[ansIndex++] = tempEven[i];  // 偶数
            ans[ansIndex++] = tempOdd[i];   // 奇数
        }
        return ans;
    }
};

// 2-不开辟新数组,使用索记录奇偶
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        int oddIndex = 1;
        int evenIndex = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0) {
                ans[evenIndex] = nums[i];
                evenIndex += 2;
            } else {
                ans[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return ans;
    }
};

// 3-在原数组上直接修改
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int oddIndex = 1;
        for (int i = 0; i < nums.size(); i += 2) {
            if (nums[i] % 2 == 1) {     // 在偶数位遇到奇数
                while (nums[oddIndex] % 2 != 0) oddIndex += 2;      // 在奇数位找下一个偶数
                swap(nums[i], nums[oddIndex]);      // 交换两个不满足条件的数字
            }
        }
        return nums;
    }
};