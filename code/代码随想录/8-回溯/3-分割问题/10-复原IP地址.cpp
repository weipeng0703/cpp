/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-24 10:01:23
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-24 11:21:02
 */
/*
力扣93. 复原 IP 地址
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。
例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。

给定一个 只包含数字 的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。
你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

示例 1：
    输入：s = "25525511135"
    输出：["255.255.11.135","255.255.111.35"]
示例 2：
    输入：s = "0000"
    输出：["0.0.0.0"]
示例 3：
    输入：s = "101023"
    输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]
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

class Solution {
public:
    vector<string> ans;
    bool isValid(const string& s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        // stoi()转出来的数字是int型，可能会越界
        // if (stoi(s) > 255 || stoi(s) < 0) return false;
        int num = 0;
        for (int i = start; i <= end; i++)
        {
            // 遇到非数字字符不合法
            if (s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if (num > 255 || num < 0) return false;
        }
        return true;
    }
    // pointNum代表当前逗号的数量
    void backtrack(string& s, int index, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, index, s.size() - 1)) ans.push_back(s);
        }
        for (int i = index; i < s.size(); i++) {
            // 如果符合要求
            if (isValid(s, index, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtrack(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);     // 删除添加的 .
            } else break;
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if (s.size() == 0) return ans;
        backtrack(s, 0, 0);
        return ans;
    }
};