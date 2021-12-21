/*
描述
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。

数据范围：字符串长度 0-10000
要求：空间复杂度 O(n)，时间复杂度 O(n)

示例一：
    输入：
    "["

    返回值：
    false    

示例二：
    输入：
    "[]"

    返回值：
    true
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return bool布尔型
     */
    bool isValid(string s) {
        stack<char> res;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                res.push(')');
            }
            else if (s[i] == '[')
            {
                res.push(']');
            }
            else if (s[i] == '{')
            {
                res.push('}');
            }
            else if (res.empty() || s[i] != res.top())
            {
                return false;
            }
            else
            {
                res.pop();
            }
    
        }
        return res.empty();
        
    }
};