/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-26 11:04:06
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-15 22:23:04
 */
/*
力扣T-3. 无重复字符的最长子串
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
    输入: s = "abcabcbb"
    输出: 3 
    解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
    输入: s = "bbbbb"
    输出: 1
    解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
    输入: s = "pwwkew"
    输出: 3
    解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
         请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.dp + hash_table
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        unordered_map<char, int> pos;
        int res = 0;
        vector<int> dp(s.size(), 0);
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) dp[i] = 1;
            else if (i != 0 && pos.find(s[i]) == pos.end()) dp[i] = dp[i - 1] + 1;
            else {
                // 寻找上一次字母s[i]出现的位置
                int j = pos[s[i]];
                // 前一次该字母出现时已经在子串中了
                if (i - j <= dp[i - 1]) dp[i] = i - j;
                // 上一次出现时不在当前最长子串中
                else dp[i] = dp[i - 1] + 1;
            }
            // 更新该字母最新出现的位置
            pos[s[i]] = i;
            res = max(res, dp[i]);
        }
        return res;
    }
};
// 2.滑动窗口
// 利用双指针，left和right，right指针遍历整个字符串，left只用于记录最近一次重复的位置，所以right - left即为无重复字符串的长度
// 初始时left = -1，向右遍历字符串，如果没有遇到重复的字符，则不含重复字符的子字符串的长度就为right - left，一直增加。
// 当出现和前面重复的字符时，将left指针移到此字符的位置，每次遇到重复的字符时，left都要更新。
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <= 1) return s.length();
        int res = 0, left = -1;
        unordered_map<char, int> pos;
        for (int right = 0; right < s.length(); right++) {
            // 当遇到重复字符时，left更新到该字符上一次出现的位置
            if (pos.find(s[right]) != pos.end()) left = max(left, pos[s[right]]);
            // 更新当前字母最新一次出现的位置
            pos[s[right]] = right;
            res = max(res, right - left);
        }
        return res;
    }
};