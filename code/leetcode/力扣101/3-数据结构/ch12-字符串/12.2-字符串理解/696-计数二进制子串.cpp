/*
给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，
并且这些子字符串中的所有 0 和所有 1 都是成组连续的。

重复出现（不同位置）的子串也要统计它们出现的次数。
 
示例 1：
    输入：s = "00110011"
    输出：6
    解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
    注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
    另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
示例 2：
    输入：s = "10101"
    输出：4
    解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
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