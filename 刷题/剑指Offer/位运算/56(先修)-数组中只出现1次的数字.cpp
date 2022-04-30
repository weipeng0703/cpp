/*
一个整型数组 nums 里除1个数字之外，其他数字都出现了两次。
请写程序找出这个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

示例 1：
    输入：nums = [4,1,4]
    输出：[1]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 
// 1.异或操作
// 答案很简单：全员进行异或操作即可。
// 考虑异或操作的性质：对于两个操作数的每一位，相同结果为 0，不同结果为 1。
// 那么在计算过程中，成对出现的数字的所有位会两两抵消为 0，最终得到的结果就是那个出现了一次的数字

class Solution {
public:
    int singleNumbers(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return -1;
        }
        int ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans ^= nums[i]; 
        }
        return ans;
    }
};
