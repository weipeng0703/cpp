/*
力扣1047. 删除字符串中的所有相邻重复项
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
在 S 上反复执行重复项删除操作，直到无法继续删除。
在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
示例 1：
    输入："abbaca"
    输出："ca"
    解释：
    例如,在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。
        之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。
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

// 1.最初版本
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        stack<char> st;
        for (char ele : s) {
            if (st.empty() || ele != st.top()) st.push(ele);
            else st.pop();
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// ★★★★★2.优化——直接用字符串做栈★★★★★
// 字符串string也有push_back，pop_back操作
class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        for (char ele : s) {
            if (ans.empty() || ans.back() != ele) ans.push_back(ele);
            else ans.pop_back();
        }
        return ans;
    }
};