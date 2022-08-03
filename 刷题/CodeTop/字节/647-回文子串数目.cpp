/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-16 17:01:59
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-02 11:47:48
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
与T5-最长回文子串结合做
力扣-647. 回文子串
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
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

// 1. dp
class Solution {
public:
    int countSubstrings(string s) {
        // dp数组判断s[i]~s[j]是否是回文子串
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
                    } else if (abs(i - j) > 1) {
                        // 如果i与j相距很远，缩小二者范围看中间的字符串是否是回文
                        // 如果中间的也是回文，因为现在这两个又相同，那么又多了一个回文子串
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


// 2-双指针法（中心延展法）
// 从字符串的每个位置开始，向左向右延长，判断存在多少以当前位置为中轴的回文字符串
class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            // 奇数序列：以s[i]为中心往两边延申
            ans += extendSubstring(s, i, i);
            // 偶数序列：以s[i]与s[i + 1]为中心向外延伸
            ans += extendSubstring(s, i, i + 1);
        }
        return ans;
    }
    // 这个地方传引用效率会提高无数倍
    // c++中参数是按值传递，如果不使用引用或者指针，则这个地方每一次函数调用，string就会被复制一次，效率很低
    // 使用引用的话函数传递的是string的引用，不会导致复制。
    int extendSubstring(string& s, int l, int r){
        int count = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};

// 3-马拉车算法

