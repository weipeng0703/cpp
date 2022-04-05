/*
力扣剑指 Offer 05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1：
    输入：s = "We are happy."
    输出："We%20are%20happy."
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

// 1.利用C++的特性
class Solution {
public:
    string replaceSpace(string s) {
        string ans;
        for (auto ele : s)
        {
            if (ele == ' ') {
                ans.push_back('%');
                ans.push_back('2');
                ans.push_back('0');
            } else {
                ans.push_back(ele);
            }
        }
        return ans;
    }
};
// 时间复杂度：$O(n)$
// 空间复杂度：$O(n)$, 开辟了新字符串空间

// 2.双指针从后向前
class Solution {
public:
    string replaceSpace(string s) {
        // 统计原字符串中空格的个数
        int count = 0;
        for (auto ele : s) {
            if (ele == ' ') ++count;
        }
        // 扩充字符串s的大小，也就是每个空格替换成"%20"之后的大小
        int sOldSize = s.size();
        s.resize(s.size() + count * 2);
        int sNewSize = s.size();
        // 从后先前将空格替换为"%20"
        for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
            if (s[j] != ' ') {
                s[i] = s[j];
            } else {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
        }
        return s;
    }
};
// 时间复杂度：$O(n)$
// 空间复杂度：$O(1)$