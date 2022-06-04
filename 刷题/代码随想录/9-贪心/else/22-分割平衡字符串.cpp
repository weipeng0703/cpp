/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-03 09:50:11
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-04 09:30:56
 */
/*
力扣1221. 分割平衡字符串
在一个 平衡字符串 中，'L' 和 'R' 字符的数量是相同的。
给你一个平衡字符串 s，请你将它分割成尽可能多的平衡字符串。
注意：分割得到的每个字符串都必须是平衡字符串，且分割得到的平衡字符串是原平衡字符串的连续子串。
返回可以通过分割得到的平衡字符串的 最大数量 。
示例 1：
    输入：s = "RLRRLLRLRL"
    输出：4
    解释：s 可以分割为 "RL"、"RRLL"、"RL"、"RL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
示例 2：
    输入：s = "RLLLLRRRLR"
    输出：3
    解释：s 可以分割为 "RL"、"LLLRRR"、"LR" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
示例 3：
    输入：s = "LLLLRRRR"
    输出：1
    解释：s 只能保持原样 "LLLLRRRR".
示例 4：
    输入：s = "RLRRRLLRLL"
    输出：2
    解释：s 可以分割为 "RL"、"RRRLLRLL" ，每个子字符串中都包含相同数量的 'L' 和 'R' 。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1-贪心策略：从前向后遍历，遇到R加加，遇到D减减，等于0时ans加一(类似匹配时栈的思想)
class Solution {
public:
    int balancedStringSplit(string s) {
        if (s.size() == 0) return 0;
        int ans = 0;
        int temp = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'R') temp++;
            else temp--;
            if (temp == 0) ans++;
        }
        return ans;
    }
};
