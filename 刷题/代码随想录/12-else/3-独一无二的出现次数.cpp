/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-26 11:29:33
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-26 14:57:23
 */
/*
力扣1207. 独一无二的出现次数
给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。
示例 1：
    输入：arr = [1,2,2,1,1,3]
    输出：true
    解释：在该数组中，1 出现了 3 次，2 出现了 2 次，3 只出现了 1 次。没有两个数的出现次数相同。
示例 2：
    输入：arr = [1,2]
    输出：false
示例 3：
    输入：arr = [-3,0,1,-3,1,1,1,-3,10,0]
    输出：true
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

// 哈希表
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int count[2002] = {0};      // 记录arr中元素出现的频率
        for (int i = 0; i < arr.size(); i++) count[arr[i] + 1000]++; 
        // 判断出现频率是不是重合(因为arr大小为1000，所以出现频率最多为1000
        bool fre[1002] = {false};
        for (int i = 0; i <= 2000; i++) {
            if (count[i]) {
                if (fre[count[i]] == false) fre[count[i]] = true;
                else return false;
            }
        }
        return true;
    } 
};