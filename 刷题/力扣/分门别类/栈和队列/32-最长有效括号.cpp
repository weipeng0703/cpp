/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

示例1:
    输入：s = "(()"
    输出：2
    解释：最长有效括号子串是 "()"
示例 2：
    输入：s = ")()())"
    输出：4
    解释：最长有效括号子串是 "()()"
示例 3：
    输入：s = "())((())"
    输出：4
    解释：最长有效括号子串是 "())((())"
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
using namespace std; 
// 1.dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                // ...()这样的情况
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } 
                // 判断形如...))的字符串前面有没有跟后一个)配对的(
                else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    // i与i-dp[i-1]-1组成了有效括号对，这是一段独立的有效括号对
                    // 如果其之前的子序列是形如(......)，那么当前位置的最长有小括号长度还要加上这一段
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};
// 时间复杂度： O(n)，n 是给定字符串的长度。我们只需要遍历字符串一次即可。
// 空间复杂度： O(n)，使用了一个长度为n的dp数组

// 2.栈
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
        {
            return 0;
        }
        int ans = 0;
        // 用于记录最后一个未被匹配到的)
        stack<int> stk;
        // 如果s中第一个字符是(,需要用-1表示前面没有被匹配到的)
        stk.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
                // 如果栈空，说明当前的右括号为没有被匹配的右括号，
                // 我们将其下标放入栈中来更新我们之前提到的「最后一个没有被匹配的右括号的下标」
                if (stk.empty())
                {
                    stk.push(i);
                }
                // 栈非空，当前右括号的下标减去上一个未被匹配到的右括号的下标即可表示中间有多少匹配成功的
                else
                {
                    ans = max(ans, i - stk.top());
                }
            }
        }
        return ans;
    }
};
// 时间复杂度： O(n)，n 是给定字符串的长度。我们只需要遍历字符串一次即可。
// 空间复杂度： O(n)。栈的大小在最坏情况下会达到 n，因此空间复杂度为 O(n) 。