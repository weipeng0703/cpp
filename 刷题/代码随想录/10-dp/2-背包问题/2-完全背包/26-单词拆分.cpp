/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-16 19:34:26
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-16 20:10:33
 */
/*
力扣139. 单词拆分
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。
示例 2：
    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
         注意，你可以重复使用字典中的单词。
示例 3：
    输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
    输出: false
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
// step1.dp[i]表示截止到第i位,s.substr(0, i)能否被字典表示
// step3.dp[i] =  if([j, i] 这个区间的子串出现在字典里 && dp[j]是true) 那么 dp[i] = true。

// 1. dp完全背包.先背包后物品
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (wordDict.size() == 0) return false;
        unordered_set<string> umap(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // 因为是要求子串，最好是遍历背包放在外循环，将遍历物品放在内循环,这样可以直接使用substr()。
        // 否则还需要额外开辟空间存放所有字串
        for (int i = 1; i < s.size(); i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (umap.find(word) != umap.end() && dp[j] == true) dp[i] = true;
            }
        }
        return dp[s.size()];
    }
};