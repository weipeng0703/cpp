/*
从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。
2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

示例 1:
    输入: [1,2,3,4,5]
    输出: True
示例二:
    输入: [0,0,1,2,5]
    输出: True
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

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int joker = 0;
        for (int i = 0; i < 4; i++)
        {
            // 计算大小王个数
            if (nums[i] == 0)
            {
                ++joker;
            }
            // 如果遇到非大小王的重复数字直接输出false(顺子中不能有重复的)
            else if (nums[i] == nums[i + 1])
            {
                return false;
            }
        }
        // 若除大小王外均不重复,判断最大数 - 0之外的最小数是否小于5(构成五张牌的顺子)
        // 如果除0之外的最大值-最小值>=5，一定有位置是用0填充不满的。
        // <=5就是为了保证空出来的位置都可以用0填满;
        // 填满后，如果遇到边界，可以向边界的另一边继续填充0，直到用完所有的0。
        return nums[4] - nums[joker] < 5;
    }
};