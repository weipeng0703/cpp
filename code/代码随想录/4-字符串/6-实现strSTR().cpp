/*
力扣 28. 实现 strStr()
实现 strStr() 函数。
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。
如果不存在，则返回  -1 。 

说明：
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与 C 语言的 strstr() 以及 Java 的 indexOf() 定义相符。

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

// 1.从haystack开始遍历
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) return 0;
        if (m > n) return -1;

        for (int i = 0; i <= n - m; i++)
        {
            // 设置标志位，记录以i位开始是否符合条件
            bool flag = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    // 只要从头检查到不符合，直接退出，说明以该位置开始不包含needle字符串
                    flag = false;
                    break;
                }
            }
            // 从haystack某一位置开始，后面几位都跟needle相同，遍历完后flag一直为true
            // 证明haystack中存在needle。直接返回第i位
            if (flag) return i;
        }
        return -1;
    }
};

// 2.使用substr库函数
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1 = haystack.size();
        int len2 = needle.size();

        if(len2 == 0) return 0;
        if(len2 > len1) return -1;

        for (int i = 0; i <= len1 - len2; i++) {
            // 注意substr(pos, len):
            // 求的是从pos开始长度为len的字串，
            // 而不是从pos到len的字串
            if(haystack.substr(i, len2) == needle) {
                return i;
                break;
            }
        }
        return -1;
    }
};

// 3.KMP算法
// https://programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html#%E5%85%B6%E4%BB%96%E8%AF%AD%E8%A8%80%E7%89%88%E6%9C%AC

// July的讲解
// https://blog.csdn.net/v_july_v/article/details/7041827