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

// 解答思路
// 括号匹配是典型的使用 栈 来解决的问题。
// 从左往右遍历，每当遇到左括号便放入栈内，遇到右括号则判断其和栈顶的括号是否是统一类型，是则从栈内取出左括号，
// 否则说明字符串不合法。

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');

            // 遍历字符串匹配的过程中，栈为空，没有匹配的字符，说明右括号没有找到对应的左括号 return false
            // 遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符.所以return false
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