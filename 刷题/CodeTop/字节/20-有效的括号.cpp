/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-05 21:27:45
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-05 21:43:41
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
力扣T-20. 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
    左括号必须用相同类型的右括号闭合。
    左括号必须以正确的顺序闭合。

注意区分——子序列可以是不连续的，但是子数组/子字符串一定要是连续的

示例 1：
    输入：s = "()"
    输出：true
示例 2：
    输入：s = "()[]{}"
    输出：true
示例 3：
    输入：s = "(]"
    输出：false
示例 4：
    输入：s = "([)]"
    输出：false
示例 5：
    输入：s = "{[]}"
    输出：true
*/

// 1-栈
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 若遍历字符串匹配的过程中，
            // (1)栈为空，没有可匹配的字符 或 
            // (2)遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符(这对应于有效字符串的条件2 ([])可   ({})不可 )。
            else if (st.empty() || st.top() != s[i]) return false;
            // 栈顶元素与 s[i] 相等，栈弹出元素，即匹配到成对出现的括号
            else st.pop();
        }
        // 遍历完字符串，若栈空表明全部匹配成功true，反之为false
        return st.empty();
    }
};