/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-21 10:31:14
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-21 11:19:37
 */

/*
力扣392. 判断子序列
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。
（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：
如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。
在这种情况下，你会怎样改变代码？

示例 1：
    输入：s = "abc", t = "ahbgdc"
    输出：true
示例 2：
    输入：s = "axc", t = "ahbgdc"
    输出：false
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

// 思路：
// 求s与t的公共子序列的长度len（与T44一模一样）,
// 如果len == s.size()证明s是子序列，否则不是
// 1. dp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (t.size() < s.size()) return false;
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                // 因为是判断s是否为t的子序列；下面那种写法不能这样写，
                // 因为那是求两个序列中的最长子序列， 不涉及谁是谁的子序列
                else dp[i][j] = dp[i][j - 1];   
            }
        }
        return dp[s.size()][t.size()] == s.size();
    }
};

// 2. T43写法
class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans == s.size();
    }
};