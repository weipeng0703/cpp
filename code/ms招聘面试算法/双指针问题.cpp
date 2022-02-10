/*
力扣T424-替换后的最长重复字符
给定一个字符串 s 和一个整数 k 。
您可以选择字符串中的任意字符，并将其更改为任何其他大写英文字符。该操作最多可执行 k 次。
在执行上述操作后，返回 包含相同字母的最长子字符串的长度 。

示例 1：
    输入：s = "ABAB", k = 2
    输出：4
    解释：用两个'A'替换为两个'B',反之亦然。
示例 2：
    输入：s = "AABABBA", k = 1
    输出：4
    解释：
    将中间的一个'A'替换为'B',字符串变为 "AABBBBA"。
    子串 "BBBB" 有最长重复字母, 答案为 4。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int maxlength = 0, left = 0, right = 0;
        vector<int> temp(26, 0);
        int res;

        while (right++ < n)
        {
            temp[s[right] - 'A']++;
            // 在这里维护 maxlength，因为每一次右边界读入一个字符，字符频数增加，
            // 才会使得 maxlength 增加
            maxlength = max(maxlength, temp[s[right] - 'A']);
            
            // 条件说明此时 k 不够用
            if (right - left + 1 - maxlength > k)
            {
                // 把其它不是最多出现的字符替换以后，都不能填满这个滑动的窗口，
                // 这个时候须要考虑左边界向右移动
                
                // 注意：移出滑动窗口的时候，频数数组中左指针维护的字符频数要相应地做减法
                // 且一定要在left++之前做
                temp[s[left] - 'A']--;
                left++;
            }
        }
        res = max(res, right - left);
        return res;

    }
};