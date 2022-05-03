/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-03 11:05:21
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-03 16:07:59
 */
/*
力扣435. 无重叠区间
给定一个区间的集合 intervals ，其中 intervals[i] = [starti, endi] 。
返回 需要移除区间的最小数量，使剩余区间互不重叠 。

示例 1:
    输入: intervals = [[1,2],[2,3],[3,4],[1,3]]
    输出: 1
    解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:
    输入: intervals = [ [1,2], [1,2], [1,2] ]
    输出: 2
    解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3：
    输入: intervals = [ [1,2], [2,3] ]
    输出: 0
    解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
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

// 1.贪心
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        if (s.size() == 0) return ans;
        vector<int> temp(26, 0);
        // 记录每个字母出现的最后位置
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a'] = i;
        }
        int pre = 0, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            // 遍历查看当前字母所处位置是否与temp中记录的最后出现位置相同
            cur = max(cur, temp[s[i] - 'a']);
            if (i == cur) {
                // 如果相同，证明该位置是一个分割点，求该段长度
                ans.push_back(cur - pre + 1);
                // pre前移继续寻找下一个符合要求的段
                pre = i + 1;
            }
        }
        return ans;
    }
};