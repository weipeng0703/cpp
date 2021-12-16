/*
给定一个整数，写一个函数来判断它是否是 4 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 4 的幂次方需满足：存在整数 x 使得 n == 4x
示例 1：

    输入：n = 16
    输出：true
示例 2：

    输入：n = 5
    输出：false
示例 3：

    输入：n = 1
    输出：true

*/
#include<vector> 
#include<cmath> 
#include <random>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;
// 方法一：log加循环（会超时）

class Solution {
public:
    bool isPowerOfFour(int n) {
        for (int i = 0; i <= n; i++)
        {
            if (i == log10(n) / log10(4))
            {
                return true;
            }
            
        }
        return false;
    }
};