/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-04 09:04:26
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-06 09:29:38
 */
/*
力扣647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由(连续)字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

力扣5. 最长回文子串
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
    string longestPalindrome(string s) {
        int maxlength = 0;
        int left = 0, right = 0;
        // dp数组判断s[i]-s[j]是否为回文子串
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // 遍历顺序从下到上，从左到右
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                string temp;
                if (s[j] == s[i]) {
                    if (abs(j - i) <= 1) {
                        dp[i][j] = true;
                    } else if (abs(i - j) > 1) {
                        if (dp[i + 1][j - 1] == true) {
                            dp[i][j] = true;
                        }
                    }
                }
                if (dp[i][j] && j - i + 1 > maxlength) {
                    maxlength = j - i + 1;
                    left = i;
                    right = j;
                }
            }
        }
        return s.substr(left, right - left + 1);
    }
};

// 2.双指针（中心延展法）
class Solution {
public:
    int ansleft = 0, ansright = 0, maxlength = 0;
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            extend(s, i, i, s.size());
            extend(s, i, i + 1, s.size());
        }
        return s.substr(ansleft, maxlength);
    }
    void extend(string& s, int left, int right, int n) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxlength) {
                ansleft = left;
                ansright = right;
                maxlength = ansright - ansleft + 1;
            }
            // 中心延伸
            left--;
            right++;
        }
    }
};