/*
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

示例 1:
    输入：s = "abaccdeff"
    输出：'b'
示例 2:
    输入：s = "" 
    输出：' '
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

// 1.哈希表存储
class Solution {
public:
    char firstUniqChar(string s) {
        if(s.size() == 0)
        {
            return ' ';
        }
        unordered_map<char, int> temp;
        for (char ch : s)
        {
            temp[ch]++;
        }
        // 因为是按照s中字母出现的顺序在哈希表中寻找的，所以一定会按s中字母出现的顺序找到结果
        for (int i = 0; i < s.size(); i++)
        {
            if (temp[s[i]] == 1)
            {
                return s[i];
            }
        }
        return ' ';
    }
};