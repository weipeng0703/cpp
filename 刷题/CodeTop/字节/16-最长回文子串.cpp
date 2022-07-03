/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-03 10:44:43
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-03 14:46:38
 */
/*
力扣-5. 最长回文子串
给你一个字符串 s，找到 s 中最长的回文子串。

示例 1：
    输入：s = "babad"
    输出："bab"
    解释："aba" 同样是符合题意的答案。
示例 2：
    输入：s = "cbbd"
    输出："bb"
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
    int left = 0, right = 0, length = 0;
    string longestPalindrome(string s) {
        // dp数组判断s[i]~s[j]是否为回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 遍历顺序从下到上，从左到右（画图就能看出来，因为比较回文，先比较首尾字母是否相同）
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (abs(j - i) <= 1) dp[i][j] = true;
                    else if (abs(j - i) > 1) {
                        if (dp[i + 1][j - 1] == true) dp[i][j] = true; 
                    }
                }
                if (dp[i][j] && j - i + 1 > length) {
                    length = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, length);
    }
};

// 2-双指针法（中心延展法）
class Solution {
public:
    int l = 0, r = 0, length = 0;
    string longestPalindrome(string s) {
        if (s.size() == 0) return "";
        for (int i = 0; i < s.size(); i++) {
            extend(s, i, i, s.size());
            extend(s, i, i + 1, s.size());
        }
        return s.substr(l, length);
    }
    void extend(string& s, int left, int right, int n) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > length) {
                // 如果符合条件且长度增加了，修改答案
                l = left;
                r = right;
                length = r - l + 1;
            }
            // 注意别延申反了(从中间向两边延申，所以left要减，right要加)
            left--;
            right++;
        }
    }
};