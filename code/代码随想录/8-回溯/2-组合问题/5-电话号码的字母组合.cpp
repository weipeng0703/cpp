/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-23 10:44:02
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-23 11:26:02
 */
/*
力扣17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
    输入：digits = "23"
    输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]
示例 2：
    输入：digits = "2"
    输出：["a","b","c"]
示例 3：
    输入：digits = ""
    输出：[]
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

// 1.回溯
class Solution {
public:
    vector<string> ans;
    string temp;
    const string letterMap[10] = {
    "", // 0
    "", // 1
    "abc", // 2
    "def", // 3
    "ghi", // 4
    "jkl", // 5
    "mno", // 6
    "pqrs", // 7
    "tuv", // 8
    "wxyz", // 9
};
    void backtrack(const string& digits, int index) {
        if (temp.size() == digits.size()) {
            ans.push_back(temp);
            return;
        }
        
        int stringIndex = digits[index] - '0';
        string letters = letterMap[stringIndex];
        // i 从 0 开始取每个数字代表的字母集中的字母，因为本题每一个数字代表的是不同集合，也就是求不同集合之间的组合，
        // 而2. 组合 (opens new window)和4.组合总和III (opens new window)都是是求同一个集合中的组合！
        for (int i = 0; i < letters.size(); i++) {
            temp.push_back(letters[i]);
            backtrack(digits, index + 1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return ans;
        backtrack(digits, 0);
        return ans;
    }
};