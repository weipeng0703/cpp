/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-22 19:27:06
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-22 22:07:10
 */

/*
力扣115. 不同的子序列
给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。
（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）
题目数据保证答案符合 32 位带符号整数范围。

示例 1：
    输入：s = "rabbbit", t = "rabbit"
    输出：3
    解释：
        如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
        rabb b it
        rab b bit
        ra b bbit
示例 2：
    输入：s = "babgbag", t = "bag"
    输出：5
    解释：
        如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
        babgbag
        babgbag
        babgbag
        babgbag
        babgbag
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
// dp[i][j]表示以i-1为结尾的s子序列中出现以j-1为结尾的t的个数
// 1. dp
class Solution {
public:
    int numDistinct(string s, string t) {
        // 注意-dp数组不能使用int类型，因为题目数据保证答案符合 32 位带符号整数范围。
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        // 字符s中出现空字符串的个数只有一种情况
        for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
        // 如果s为空字符串，他是不会有子序列的
        for (int i = 0; i < t.size(); i++) dp[0][i] = 0;
        // 空字符串中出现空字符串只有一种情况
        dp[0][0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                // 例如bagg和bag i == 4 && j == 3 的情况
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};