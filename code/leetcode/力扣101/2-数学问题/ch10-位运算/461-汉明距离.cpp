/*
两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。(两个数的二进制表示中对应位置不同的个数)

示例 1：

    输入：x = 1, y = 4
    输出：2
    解释：
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑
    上面的箭头指出了对应二进制位不同的位置。
示例 2：

    输入：x = 3, y = 1
    输出：1
*/
#include<vector> 
#include<cmath> 
#include <random>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;
// 方法一：内置函数
class Solution {
public:
    int hammingDistance(int x, int y) {
        // 内置了计算二进制表达中 1 的数量的函数
        return __builtin_popcount(x ^ y);
    }
};

// 方法二:异或
class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = x ^ y, res = 0;
        while (diff)
        {
            res += diff & 1;  // 注意这个地方的1是0001而不是1111呀！x & 1目的是取x的最后一位，若是1，res++
            diff >>= 1;     // diff右移一位继续判断下一位
        }
        return res;
    }
};