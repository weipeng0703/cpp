/*
给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 的数组 ans 作为答案。

示例 1：

    输入：n = 2
    输出：[0,1,1]
    解释：
    0 --> 0
    1 --> 1
    2 --> 10

示例 2：

    输入：n = 5
    输出：[0,1,1,2,1,2]
    解释：
    0 --> 0
    1 --> 1
    2 --> 10
    3 --> 11
    4 --> 100
    5 --> 101
*/
#include<vector> 
#include<cmath> 
#include <random>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一：BK算法
class Solution {
public:
    // Brian Kernighan算法
    // 对于任意整数x,令x = x&(x - 1)，该运算将x的二进制表示的最后一位1变为0，因此，对x重复此操作，直到x变为0，
    // 操作的次数即为x的“一比特数”
    int countOnes(int x) {
        int counts = 0;
        while (x) {
            x &= (x - 1);
            counts++;
        }
        return counts;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};

// 有多种动态规划算法，之后刷到动态规划再做
