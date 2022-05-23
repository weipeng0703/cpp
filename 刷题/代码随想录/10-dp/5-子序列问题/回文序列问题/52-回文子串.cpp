/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-23 10:08:05
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-23 15:09:39
 */

/*
力扣647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由(连续)字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
    输入：s = "abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"
示例 2：
    输入：s = "aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
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
    int countSubstrings(string s) {
        // dp数组判断s[i]-s[j]内的回文子串数量
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int ans = 0;
        // 遍历顺序是从下往上，从左往右
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    // 如果是单个字符或者两个相邻的字符相同一定是回文
                    if (abs(i - j) <= 1) {
                        ans++;
                        dp[i][j] = true;
                    } else if (abs(i - j) > 1) {    // 如果j与j相距很远，则缩小二者范围看中间的字符串是否是回文
                        if (dp[i + 1][j - 1] == true) {
                            ans++;
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

// 2. 中心延伸法
// 从字符串的每个位置开始，向左向右延长，判断存在多少以当前位置为中轴的回文字符串
class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size(), ans = 0;

        for (int i = 0; i < size; i++) {
            // 奇数序列：以s[i]为中心往两边延申
            ans += extendSubstring(s, i, i);
            // 偶数序列：以s[i]与s[i + 1]为中心向外延伸
            ans += extendSubstring(s, i, i + 1);
        }
        return ans;
    }
    int extendSubstring(string s, int l, int r){
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};
