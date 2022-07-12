/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-11 19:04:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-11 20:07:30
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
力扣T-10. 正则表达式匹配
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

示例 1：
    输入：s = "aa", p = "a"
    输出：false
    解释："a" 无法匹配 "aa" 整个字符串。
示例 2:
    输入：s = "aa", p = "a*"
    输出：true
    解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
    因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：
    输入：s = "ab", p = ".*"
    输出：true
    解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
*/

// substr有2种用法：
// 假设：string s = "0123456789";
// string sub1 = s.substr(5); //只有一个数字5表示从下标为5开始 一直到结尾：sub1 = "56789"
// string sub2 = s.substr(5, 3); //从下标为5开始截取长度为3位：sub2 = "567"

// 1-递归判断
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) return s.empty();
        // 整个字符串的首字母是否匹配
        bool first_match = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.length() >= 2 && p[1] == '*') {
            // 前者表示跳过*字符
            // 后者表示使用*匹配一个字符
            return isMatch(s, p.substr(2)) || (first_match && isMatch(s.substr(1), p));
        } else {
            // 表示第一个字符可以匹配上
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};
