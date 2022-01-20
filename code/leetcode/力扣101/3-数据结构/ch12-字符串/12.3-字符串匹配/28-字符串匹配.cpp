/*
实现 strStr() 函数。

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串
出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。
这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

示例 1：
    输入：haystack = "hello", needle = "ll"
    输出：2
示例 2：
    输入：haystack = "aaaaa", needle = "bba"
    输出：-1
示例 3：
    输入：haystack = "", needle = ""
    输出：0
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.思路：直接使用substr()方法
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();

        if(len2 == 0)
        {
            return 0;
        }
        
        else if(len2 > len1)
        {
            return -1;
        }

        for (int i = 0; i <= len1 - len2; i++)
        {
            // 一定要注意substr(pos, len)的用法:
            // 求的是从pos开始长度为len的字串，
            // 而不是从pos到len的字串
            if(haystack.substr(i, len2) == needle)
            {
                return i;
                break;
            }
        }
        return -1;
    }
};

// 方法二：KMP算法
// 这个写的不错可以康康
// https://leetcode-cn.com/problems/implement-strstr/solution/guan-yu-wo-di-yi-ci-kan-kmp-suan-fa-jiu-sqs0d/
