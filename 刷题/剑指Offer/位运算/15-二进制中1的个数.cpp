/*
编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。

示例 1:
    输入：n = 11 (控制台输入 00000000000000000000000000001011)
    输出：3
    解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
示例 2:
    输入：n = 128 (控制台输入 00000000000000000000000010000000)
    输出：1
    解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// 位运算
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ret = 0;
        for (int i = 0; i < 32; i++)
        {
            // 1 << i 每次将1扩大两倍（即后面加1个0），与n做与运算
            // 如果原数n中当前位置上为1，那么与10...0与运算有结果，证明该位置存在1，ret++
            if (n & (1 << i))
            {
                ret++;
            }
            
        }
        return ret;
    }
};
// 位运算优化
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while (n)
        {
            n = n & (n - 1);
            ans++;
        }
        return ans;
    }
};