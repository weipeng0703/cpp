/*
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。

输入: s = "aba"
输出: true

输入: s = "abca"
输出: true
解释: 你可以删除c字符。

输入: s = "abc"
输出: false
*/
#include<vector> 
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

class Solution {
public:
    bool checkhuiwen(string s, int start, int end)
    {
        for (int i = start, j = end; i < j; ++i, --j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }


    bool validPalindrome(string s) {
        int start = 0, end = s.size()-1;
        while (start < end)
        {
            // 如果字符本身就是回文串直接输出true
            if (s[start] == s[end])
            {
                start++;
                end--;
            }
            else
            {
                // 贪心
                return checkhuiwen(s, start, end-1)||checkhuiwen(s, start+1, end);
            }
            
        }
        return true;
        
    }
};