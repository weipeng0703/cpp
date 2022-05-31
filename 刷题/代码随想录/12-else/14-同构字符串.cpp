/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-31 15:56:48
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-31 16:05:21
 */
/*
力扣205. 同构字符串
给定两个字符串 s 和 t ，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

示例 1:
    输入：s = "egg", t = "add"
    输出：true
示例 2：
    输入：s = "foo", t = "bar"
    输出：false
示例 3：
    输入：s = "paper", t = "title"
    输出：true
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

// 1.用两个哈希表分别保存s[i]->t[j] 和 t[i]->s[j],如果映射不同立即返回false
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> map1;
        unordered_map<char, char> map2;
        for (int i = 0, j = 0; i < s.size(), j < t.size(); i++, j++) {
            if (map1.find(s[i]) == map1.end()) map1[s[i]] = t[j];
            if (map2.find(t[i]) == map2.end()) map2[t[i]] = s[j];
            if (map1[s[i]] != t[j] || map2[t[i]] != s[j]) return false;
        }
        return true;
    }
};