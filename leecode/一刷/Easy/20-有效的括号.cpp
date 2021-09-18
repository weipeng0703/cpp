/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
 

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

#include<vector>
#include<unordered_map>
#include<iostream>
#include<string>
#include<stack>
using namespace std;

// 解答思路：括号匹配是栈的经典问题

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {  // 序号必须得反过来写
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch : s) 
        {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');

            // 第三种情况：遍历字符串匹配的过程中，栈为空，没有匹配的字符，
            // 说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。
            // 所以return false
            else if (st.empty() || st.top() != s[i]) return false;

            else st.pop(); // 栈顶元素与 s[i] 相等，栈弹出元素，即匹配到成对出现的括号
        }
        
        if (st.empty())   // 遍历完字符串，栈空了，所以return true
        {
            return true;    
        }
        else               // 栈没空，return false
        {
            return false;
        }
        
        
    }
};