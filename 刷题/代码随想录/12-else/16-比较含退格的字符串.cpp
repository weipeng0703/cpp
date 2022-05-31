/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-31 16:52:51
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-31 18:35:47
 */
/*
力扣844. 比较含退格的字符串
给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
注意：如果对空文本输入退格字符，文本继续为空。

示例 1：
    输入：s = "ab#c", t = "ad#c"
    输出：true
    解释：s 和 t 都会变成 "ac"。
示例 2：
    输入：s = "ab##", t = "c#d#"
    输出：true
    解释：s 和 t 都会变成 ""。
示例 3：
    输入：s = "a#c", t = "b"
    输出：false
    解释：s 会变成 "c"，但 t 仍然是 "b"。
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

// 不能用哈希表，因为字符串中的字母是有顺序的
// 1-双指针遍历两个字符串，分别保存除了# 与对应字母后的结果，比较两个结果      超时
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1;       // 保存去除了s中的# 与对应字母后的结果
        string temp1;       // 保存去除了t中的# 与对应字母后的结果
        int i = s.size() - 1, j = t.size() - 1;
        while (i >= 0) {
            if (s[i] != '#') {
                temp1.push_back(s[i]);
                i--;
            } else if (i >= 2 && s[i] == '#' && s[i - 1] != '#') {
                i -= 2;
            } else if (i >= 4 && s[i] == '#' && s[i - 1] == '#') {
                i -= 4;
            }
        }
        while (j >= 0) {
            if (t[j] != '#') {
                temp2.push_back(t[j]);
                j--;
            } else if (j >= 2 && t[j] == '#' && t[j - 1] != '#') {
                j -= 2;
            } else if (j >= 4 && t[j] == '#' && t[j - 1] == '#') {
                j -= 4;
            }
        }
        if (temp1.size() != temp2.size()) return false;
        for (int i = 0; i < temp1.size(); i++) {
            if (temp1[i] != temp2[i]) return false;
        }
        return true;
    }
};

// 2.使用栈的思想（最好理解的方法）
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1;       // 存储处理完的s字符串
        string temp2;       // 存储处理完的t字符串

        for (int i = 0; i < s.size(); i++) {
            // 非#的字符入栈
            if (s[i] != '#') temp1 += s[i];
            // 遇到#，如果temp1不为空，弹出一个前面的字符
            else if (!temp1.empty()) temp1.pop_back();
        }
        for (int i = 0; i < t.size(); i++) {
            // 非#的字符入栈
            if (t[i] != '#') temp2 += t[i];
            // 遇到#，如果temp1不为空，弹出一个前面的字符
            else if (!temp2.empty()) temp2.pop_back();
        }
        if (temp1 == temp2) return true;
        return false;
    }
};

// 简化
class Solution {
public:
    string getString(const string& s) {
        string temp1;
        for (int i = 0; i < s.size(); i++) {
            // 非#的字符入栈
            if (s[i] != '#') temp1 += s[i];
            // 遇到#，如果temp不为空，弹出一个前面的字符
            else if (!temp1.empty()) temp1.pop_back();
        }
        return temp1;
    }
    bool backspaceCompare(string s, string t) {
        return getString(s) == getString(t);
    }
};
// 3.双指针
// 同时从后向前遍历S和T（i初始为S末尾，j初始为T末尾），记录#的数量，模拟消除的操作，如果#用完了，就开始比较S[i]和S[j]。
// 如果S[i]和S[j]不相同返回false，如果有一个指针（i或者j）先走到的字符串头部位置，也返回false。
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int sSkipNum = 0, tSkipNum = 0;
        int i = s.size() - 1, j = t.size() - 1;
        while (1) {
            while (i >= 0) {
                if (s[i] == '#') sSkipNum++;
                else {
                    if (sSkipNum > 0) sSkipNum--;
                    else break;
                }
                i--;
            }
            while (j >= 0) {
                if (t[j] == '#') tSkipNum++;
                else {
                    if (tSkipNum > 0) tSkipNum--;
                    else break;
                }
                j--;
            }
            // 后面的 # 消除完了，比较前面剩余的字符
            if (i < 0 || j < 0) break;      // 某一个字符串遍历了，退出循环
            if (s[i] != t[j]) return false;
            i--;
            j--;
        }
        if (i == -1 && j == -1) return true;
        return false;
    }
};