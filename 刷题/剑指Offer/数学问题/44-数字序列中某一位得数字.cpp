/*
数字以0123456789101112131415…的格式序列化到一个字符序列中。
在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。
请写一个函数，求任意第n位对应的数字。

示例 1：
    输入：n = 3
    输出：3
示例 2：
    输入：n = 11
    输出：0
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

// 补位
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

// 找规律
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1, weigh = 1;  /* len表示当前数(十进制)的位数, weigh表示当前位的权重(10^i)...  */
        while (n > (long long) 9 * weigh * len) /* 转换成long long, 防止整型溢出 */
        {  
            n -= 9 * weigh * len;
            len++;
            weigh *= 10;
        }
        int curNum = (n - 1)/len + weigh;     // curNum是含有所找digit的那个数, 整个数列的第一个数是1
        int resDigit = 0;
        for (int i = (n-1) % len; i < len; i++)  // 从低位向高位移动扫描, 根据离末位的偏移量找到所找的数字
        {
            resDigit = curNum % 10;
            curNum /= 10;
        }
        return resDigit;
    }
};