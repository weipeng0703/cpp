/*
输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理。
例如输入字符串"I am a student. "，则输出"student. a am I"。

示例 1：
    输入: "the sky is blue"
    输出: "blue is sky the"
示例 2：
    输入: "  hello world!  "
    输出: "world! hello"
    解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
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
using namespace std; 
// 双指针
class Solution {
public:
    string reverseWords(string s) 
    {
        string res;
        for(int right = s.size() - 1; right >= 0; --right)
        {
            if(s[right] == ' '){
                continue;
            }
            int left = right;
            while(left >= 0 && s[left] != ' '){
                left--;
            }
            // 注意细节：此时left已经滑到单词左边第一个空格了
            res.append(s.substr(left + 1, right - left));
            res.append(" ");
            right = left;
        }
        //细节：因为之前循环最后加了一个空格，所以去除最后一个字符空格
        if(!res.empty()){
            res.pop_back();
        }
        return res;
    }
};