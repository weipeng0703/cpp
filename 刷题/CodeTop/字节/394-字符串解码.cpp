/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-13 16:20:27
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-13 16:54:07
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
力扣T-394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。

示例 1：
    输入：s = "3[a]2[bc]"
    输出："aaabcbc"
示例 2：
    输入：s = "3[a2[c]]"
    输出："accaccacc"
示例 3：
    输入：s = "2[abc]3[cd]ef"
    输出："abcabccdcdcdef"
示例 4：
    输入：s = "abc3[cd]xyz"
    输出："abccdcdcdxyz"
*/

// 1-括号匹配用栈
class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<int> nums;
        stack<string> strs;
        int num = 0;
        if (s.size() == 0) return ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') num = num * 10 + s[i] - '0';
            else if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) ans += s[i];
            //将‘[’前的数字压入nums栈内， 字母字符串压入strs栈内
            // 即碰到[进行压栈和压栈后的清零工作
            else if (s[i] == '[') {
                nums.push(num);
                num = 0;
                strs.push(ans);
                ans = "";
            } else if (s[i] == ']') {
                //遇到‘]’时，操作与之相配的‘[’之间的字符，使用分配律
                // 即碰到]进行求解操作
                int times = nums.top();
                nums.pop();
                for (int i = 0; i < times; i++) strs.top() += ans;
                ans = strs.top();
                strs.pop();
            }
        }
        return ans;
    }
};
