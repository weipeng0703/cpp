/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-22 21:52:08
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-22 22:13:19
 */

/*
力扣583. 两个字符串的删除操作
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
每步 可以删除任意一个字符串中的一个字符。

示例 1：
    输入: word1 = "sea", word2 = "eat"
    输出: 2
    解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"
示例  2:
    输入：word1 = "leetcode", word2 = "etco"
    输出：4
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
// 1. 求出两个单词的最长公共子序列长度ans(跟T44一模一样)
// 2.
// 如果len == 两个单词任一个单词的长度，答案为另一个单词的长度 - len
// 如果len都 ！= 两个单词任意一个的长度， 答案为 (一个单词的长度 - len) + (另一个单词的长度 - len)

// 1. dp
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        int ans = 0;
        int res = 0;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        if (ans == word1.size() && word1.size() == word2.size()) res = word2.size() - ans;
        if (ans == word1.size() && ans != word2.size()) res = word2.size() - ans;
        if (ans != word1.size() && ans == word2.size()) res = word1.size() - ans;
        if (ans != word1.size() && ans != word2.size()) res = (word1.size() - ans) + (word2.size() - ans);
        return res;
    }
};