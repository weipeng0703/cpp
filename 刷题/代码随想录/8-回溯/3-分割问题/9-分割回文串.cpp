/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-24 09:07:28
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-24 09:46:21
 */
/*
力扣131. 分割回文串
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。
回文串 是正着读和反着读都一样的字符串。

示例 1：
    输入：s = "aab"
    输出：[["a","a","b"],["aa","b"]]
示例 2：
    输入：s = "a"
    输出：[["a"]]
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

// 注意：
// 1.判断字符串回文的时候可以传入left和right两个参数，
// 这样可以方便后续的操作，例如后续如果求该子字符串，可以直接使用s.substr(left, right)的方式

// 1.等价于组合问题
class Solution {
public:
    vector<vector<string>> ans;
    vector<string> path;
    bool isHuiwen(const string& str, int left, int right) {
        while (left <= right) {
            if (str[left] == str[right]) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        return true;
    }
    void backtrack(const string& str, int index) {
        if (index >= str.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < str.size(); i++){
            if (isHuiwen(str, index, i)) {
                string tempStr = str.substr(index, i - index + 1);
                path.push_back(tempStr);
            } else {
                continue;
            }
            backtrack(str, i + 1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return ans;
        backtrack(s, 0);
        return ans;
    }
};