/*
请实现一个函数用来匹配包含'. '和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"(b和c出现0次)匹配，但与"aa.a"和"ab*a"均不匹配。
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
using namespace std; 

// 1.字符串递归

// substr有2种用法：

// 假设：string s = "0123456789";
// string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始一直到结尾：sub1 = "56789"
// string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        
        auto first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        
        if (p.length() >= 2 && p[1] == '*') {
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        }
        else {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};