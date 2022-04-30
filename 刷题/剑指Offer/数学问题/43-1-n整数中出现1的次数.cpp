/*
同力扣T233
输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。
例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。
示例 1：
    输入：n = 12
    输出：5
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<math.h>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// 1.暴力解法（会超时）
class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int num = i;
            while (num != 0) {
                // 从个位数开始一位一位的和1比较
                if (num % 10 == 1) {
                    count++;
                }
                num /= 10;
            }
            ans += count;
        }
        return ans;
    }
};
// 2.dp（超内存）
// 假如要求123里面含有1的数量，只要求最后一位中1的数量 和 除了最后一位中1的数量即可
// 即 dp[i] = dp[i % 10] + dp[i / 10]
class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        vector<int> dp(n + 1);
        dp[1] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            dp[i] = dp[i % 10] + dp[i / 10];
            ans += dp[i];
        }
        return ans;
    }
};
// 3.找规律
class Solution {
public:
    int countDigitOne(int n) {
        if (n == 0) return 0;
        int ans = 0;
        for (long long i = 1; i <= n; i *= 10)
        {
            // 注意  long long 数与 0 作比较，要用0LL代替0
            ans += (n / (i * 10)) * i + min(max(n % (i * 10) - i + 1, 0LL), i);
        }
        return ans;
    }
};

// 4.巧妙方法-补位
class Solution {
public:
    int findNthDigit(long n) {
        int k = 1;
        while (k * pow(10, k) < n){
            n += pow(10, k);
            k += 1;
        }
        return to_string(n/k)[n % k] - '0';
    }
};