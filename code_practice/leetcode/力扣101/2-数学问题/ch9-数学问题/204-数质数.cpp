/*
统计所有小于非负整数 n 的质数的数量。

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。

示例 2：

输入：n = 0
输出：0

示例 3：

输入：n = 1
输出：0
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:暴力法会超时
class Solution {
public:
    bool isPrime(int x) {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            ans += isPrime(i);
        }
        return ans;
    }
};

// 方法二:埃氏筛选法
class Solution {
public:
    int countPrimes(int n) {
    int count = 0;
     // vector的初始化，生成n个元素，每个元素都初始化为1（真）
    vector<bool> signs(n, true);
    for (int i = 2; i < n; i++) {
        // 遍历，对于质数，count++，并将其所有倍数排除，在之后的循环中，遇到合数会直接pass不去管它
        if (signs[i]) {
            count++;
            // 对于所有i的倍数，他们都是合数
            for (int j = i + i; j < n; j += i) {
                signs[j] = false;
            }
        }
    }
    return count;
}
};