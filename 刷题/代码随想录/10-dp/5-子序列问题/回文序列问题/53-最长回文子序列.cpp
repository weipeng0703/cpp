/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-23 11:26:58
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-23 15:12:12
 */

/*
力扣516. 最长回文子序列
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

示例 1：
    输入：s = "bbbab"
    输出：4
    解释：一个可能的最长回文子序列为 "bbbb" 。
示例 2：
    输入：s = "cbbd"
    输出：2
    解释：一个可能的最长回文子序列为 "bb" 
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

// 1. dp
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        // 一个字符一定是回文子序列，长度为1
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        // 从下到上
        for (int i = s.size() - 1; i >= 0; i--) {
            // 从左到右,因为dp[i][i]已经被初始化为1了
            // 所以j要从i + 1开始
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            } 
        }
        // 输出结果是字符串从头到尾范围内的值
        return dp[0][s.size() - 1];
    }
};