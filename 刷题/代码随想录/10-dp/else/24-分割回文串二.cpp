/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-04 10:31:24
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-04 11:12:31
 */
/*
力扣132. 分割回文串 II
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。
返回符合要求的 最少分割次数 。

示例 1：
    输入：s = "aab"
    输出：1
    解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
示例 2：
    输入：s = "a"
    输出：0
示例 3：
    输入：s = "ab"
    输出：1
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

// 1-dp
class Solution {
public:
    int minCut(string s) {
        // 判断是否是回文
        vector<vector<bool>> temp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if ((s[i] == s[j] && abs(j - i) <= 1) || (s[i] == s[j] && temp[i + 1][j - 1])) {
                    temp[i][j] = true;
                }
            }
        }
        vector<int> dp(s.size(), INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            if (temp[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (temp[j + 1][i]) {
                    // 此处不是拿dp[i]与dp[j] + 1相比，
                    // 是求出dp[j] + 1后与之前得到的最小的分割次数作比较
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};