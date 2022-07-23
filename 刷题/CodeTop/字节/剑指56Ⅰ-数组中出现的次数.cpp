/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 11:20:31
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 14:34:14
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
力扣-剑指 Offer 56 - I. 数组中数字出现的次数
一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。
要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
    输入：nums = [4,1,4,6]
    输出：[1,6] 或 [6,1]
示例 2：
    输入：nums = [1,2,10,4,1,4,3,3]
    输出：[2,10] 或 [10,2]
*/ 
// 1-位运算

// 把所有数字分成两组，使得：
//     两个只出现一次的数字在不同的组中；
//     相同的数字会被分到相同的组中。
// 那么对两个组分别进行异或操作，即可得到答案的两个数字。这是解决这个问题的关键。
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int temp = 0;
        // 求两个只出现一次的数字的异或值
        for (auto ele : nums) temp ^= ele;
        // 求temp出现1的最低位（左移将1往前进）
        int div = 1;
        while ((div & temp) == 0) div <<= 1;
        int a = 0, b = 0;
        // 将nums分组
        // 每组中的异或值即为只出现一次的数字
        for (auto ele : nums) {
            if((ele & div)){
                a ^= ele;
            } else{
                b ^= ele;
            }
        }
        return vector<int>{a, b};
    }
};