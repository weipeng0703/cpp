/*
给定一个整数，写一个函数来判断它是否是 3 的幂次方。如果是，返回 true ；否则，返回 false 。

整数 n 是 3 的幂次方需满足：存在整数 x 使得 n == 3的x次方

示例 1：

    输入：n = 27
    输出：true
示例 2：

    输入：n = 0
    输出：false
示例 3：

    输入：n = 9
    输出：true
示例 4：

    输入：n = 45
    输出：false
*/
#include<vector> 
#include<cmath> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 试除法
// 我们不断地将 n 除以 3，直到 n=1。如果此过程中 n 无法被 3 整除，就说明 n 不是 3 的幂。

// 本题中的 n 可以为负数或 0，可以直接提前判断该情况并返回 false，也可以进行试除，因为负数或 0 也无法通过多次除以 3 得到 1。

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        while (n % 3 == 0) n /= 3;
        return n == 1;
    }
}

// 使用对数
// 设 logn3 = m，如果 n 是 3 的整数次方，那么 m 一定是整数。
class Solution {
public:
    bool isPowerOfThree(int n) {
        // fmod(double x, double y)返回x除以y的余数
        // 注意log后面跟着10
        return fmod(log10(n) / log10(3), 1) == 0;

    }
};