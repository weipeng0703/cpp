/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-03 15:10:50
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-03 15:58:43
 */
/*
力扣763. 划分字母区间
字符串 S 由小写字母组成。我们要把这个字符串划分为 尽可能多 的片段，同一字母最多出现在一个片段中。
返回一个表示每个字符串片段的长度的列表。

示例 1:
    输入：S = "ababcbaca defegde hijhklij"
    输出：[9,7,8]
    解释：
    划分结果为 "ababcbaca", "defegde", "hijhklij"。
    每个字母最多出现在一个片段中。
    像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
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

// 1.
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        if (s.size() == 0) return ans;
        vector<int> temp(26, 0);
        int pre = 0;
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a'] = i;
        }
        int pre = 0, cur = 0;
        for (int i = 0; i < s.size(); i++) {
            cur = max(cur, temp[s[i] - 'a']);
            if (i == cur) {
                ans.push_back(cur - pre + 1);
                pre = i + 1;
            }
        }
        return ans;
    }
};