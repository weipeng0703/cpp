/*
力扣242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:
    输入: s = "anagram", t = "nagaram"
    输出: true
示例 2:
    输入: s = "rat", t = "car"
    输出: false
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

// 1.创建两个数组记录次数后对比
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;     // 前两种情况可以用这句代替
        if (s.size() == 0 && t.size() != 0) return false;
        if (s.size() != 0 && t.size() == 0) return false;
        if (s.size() == 0 && t.size() == 0) return true;

        vector<int> numS(26, 0);
        vector<int> numT(26, 0);
        // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
        for (int i = 0; i < s.size(); i++) {
            numS[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size(); i++) {
            numT[t[i] - 'a']++;
        }
        for (int i = 0; i < numS.size(); i++) {
            if (numS[i] != numT[i]) {
                return false;
            }
        }
        return true;
    }
};

// 2.一个数组即可，很聪明的解法
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return false;     // 前两种情况可以用这句代替
        if (s.size() == 0 && t.size() != 0) return false;
        if (s.size() != 0 && t.size() == 0) return false;
        if (s.size() == 0 && t.size() == 0) return true;

        vector<int> ans(26, 0);
        for (int i = 0; i < s.size(); i++) ++ans[s[i] - 'a'];
        for (int i = 0; i < t.size(); i++) --ans[t[i] - 'a'];
        
        for(auto ele : ans) {
            if (ele != 0) return false;
        }
        return true;
    }
};