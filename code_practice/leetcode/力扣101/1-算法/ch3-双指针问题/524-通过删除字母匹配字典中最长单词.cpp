/*
给你一个字符串 s 和一个字符串数组 dictionary ，找出并返回 dictionary 中最长的字符串，
该字符串可以通过删除 s 中的某些字符得到。

如果答案不止一个，返回长度最长且字母序最小的字符串。如果答案不存在，则返回空字符串。

示例：
输入：s = "abpcplea", dictionary = ["ale","apple","monkey","plea"]
输出："apple"

输入：s = "abpcplea", dictionary = ["a","b","c"]
输出："a"
*/
#include<vector> 
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size(), m = t.size();

        if (m > n)
        {
            return false;
        }

        int i = 0;
        for (char ch:t)
        {
            while (i < n && s[i] != ch)     // 不能在while()里面定义int i < n
            {
                i++;
            }
            // 如果在s序列中没有这个ch，则返回false
            if (i >= n)
            {
                return false;
            } 
            i++;
        }
        return true;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        // 先将字典进行排序：更长的，字典序更小的排在前面
        sort(dictionary.begin(), dictionary.end(),[&](string &a, string &b){
            if (a.size() == b.size())
            {
                return a < b;
            }
            return a.size() > b.size();
        });
        // 依次比较字典中的字符串与s
        for (string &t : dictionary)
        {
            if (isSubsequence(s, t) == true)
            {
                return t;
            }
            
        }
        return "";
    }
};   