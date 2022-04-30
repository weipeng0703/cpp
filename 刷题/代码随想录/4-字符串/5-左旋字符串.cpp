/*
力扣 剑指 Offer 58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。

示例 1：
    输入: s = "abcdefg", k = 2
    输出: "cdefgab"
示例 2：
    输入: s = "lrloseumgh", k = 6
    输出: "umghlrlose"
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

// 1.利用C++特性
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        string ans;
        // 先将原字符串第n位到最后的字符放入
        for (int i = n; i < s.length(); i++) ans.push_back(s[i]);
        // 再将原字符串从头到第n位的字符放入
        for (int j = 0; j < n; j++) ans.push_back(s[j]);
        return ans;
    }
};

// 2.不申请新的空间 多次reverse
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        reverse(s.begin(), s.end());
        reverse(s.begin(), s.begin() + s.size() - n);
        reverse(s.begin() + s.size() - n, s.end());
        return s;
    }
};