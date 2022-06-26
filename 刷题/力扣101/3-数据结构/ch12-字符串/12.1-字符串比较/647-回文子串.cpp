/*
给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。
回文字符串 是正着读和倒过来读一样的字符串。
子字符串 是字符串中的由连续字符组成的一个序列。
具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
    输入：s = "abc"
    输出：3
    解释：三个回文子串: "a", "b", "c"
示例 2：
    输入：s = "aaa"
    输出：6
    解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/

#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.中心拓展法
// 从字符串的每个位置开始，向左向右延长，判断存在多少以当前位置为中轴的回文字符串
class Solution {
public:
    int countSubstrings(string s) {
        int size = s.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            // 奇数序列：即中心是一个字符
            count += extendSubstring(s, i, i);      
            // 偶数序列：即中心是两个字符
            count += extendSubstring(s, i, i + 1);  
        }
        return count;
        
    }
    int extendSubstring(string s, int l, int r)
    {
        int count = 0;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            --l;
            ++r;
            ++count;
        }
        return count;
    }
};