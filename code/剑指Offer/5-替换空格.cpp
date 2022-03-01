/*
请实现一个函数，将一个字符串s中的每个空格替换成“%20”（即空格的ASCII码转换得来的16进制数字）。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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
// 利用C++特性
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto& c : s)
        {
            if (c == ' ')
            {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};