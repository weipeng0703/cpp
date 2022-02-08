/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。
请你判断是否可以利用字典中出现的单词拼接出 s 。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
    输入: s = "leetcode", wordDict = ["leet", "code"]
    输出: true
    解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
    输入: s = "applepenapple", wordDict = ["apple", "pen"]
    输出: true
    解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
         注意，你可以重复使用字典中的单词。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.DP
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] == true;
        // 考虑每个分割位置时，需要遍历字符串集合，以确定当前位置是否可以成功分割
        for (int i = 1; i <= n; i++)
        {
            for (const string& word : wordDict)
            {
                int len = word.length();
                // substr(起始位置， 长度)
                if (i >= len && s.substr(i - len, len) == word)
                {
                    dp[i] = dp[i] || dp[i - len];
                }
                
            }
            
        }
        return dp[n];
    }
};