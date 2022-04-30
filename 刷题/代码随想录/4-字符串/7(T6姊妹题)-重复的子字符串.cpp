/*
 * @Descripttion: My project
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-07 16:26:25
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-07 16:51:20
 */
/*
力扣 459. 重复的子字符串
给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

示例 1:
    输入: s = "abab"
    输出: true
    解释: 可由子串 "ab" 重复两次构成。
示例 2:
    输入: s = "aba"
    输出: false
示例 3:
    输入: s = "abcabcabcabc"
    输出: true
    解释: 可由子串 "abc" 重复四次构成。 (或子串 "abcabc" 重复两次构成。)
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

// 1.跟上一题解法类似，遍历字符串
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();

        for (int i = 1; i * 2 <= n; i++)
        {
            if (n % i == 0) {
                bool flag = true;
                for (int j = i; j < n; j++) {
                    if (s[j] != s[j - i]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) return true;
            }
        }
        return false;
    }
};

// 2.KMP算法
