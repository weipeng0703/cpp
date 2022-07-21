/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-21 11:15:38
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-21 11:15:59
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
/*
力扣T-72. 编辑距离
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数。
你可以对一个单词进行如下三种操作：
    插入一个字符
    删除一个字符
    替换一个字符
示例 1：
    输入：word1 = "horse", word2 = "ros"
    输出：3
    解释：
    horse -> rorse (将 'h' 替换为 'r')
    rorse -> rose (删除 'r')
    rose -> ros (删除 'e')
示例 2：
    输入：word1 = "intention", word2 = "execution"
    输出：5
    解释：
    intention -> inention (删除 't')
    inention -> enention (将 'i' 替换为 'e')
    enention -> exention (将 'n' 替换为 'x')
    exention -> exection (将 'n' 替换为 'c')
    exection -> execution (插入 'u')
*/

// 1. dp
// dp[i][j]表示由word1.sub(0, i)到word2.sub(0, j)需要操作的次数
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 由word1.sub(0, i)到空字符串需要删减i步
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        // 由空字符串到word2.sub(0, j)需要增加i步
        for (int i = 0; i <= word2.size(); i++) dp[0][i] = i;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                // 如果两个字符串当前位置相等，那么只需要看前面的字符操作的次数，当前这一步不需要动
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else {
                    // 如果两个字符串当前位置不相等，肯定需要加一步操作，那么总操作数就看前面三个方向上的操作数中的最小值
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};