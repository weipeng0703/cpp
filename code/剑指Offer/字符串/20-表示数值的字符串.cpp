/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。

示例 1：
    输入：s = "."
    输出：false
示例 2：
    输入：s = "    .1  "
    输出：true
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
using namespace std; 
// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
// 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
class Solution {
private:
    // 检查整数的正负
    // 扫描字符串中 +/-为起始的0~9的数位，对应于字符串中A和C的部分
    bool scanInt(const string s, int& index){
        if (s[index] == '+' || s[index] == '-')
        {
            ++index;
        }
        return scanUnsignedInt(s, index);
    }
    // 扫描字符串中0~9的数位，对应于字符串中B的部分，没有符号哦
    bool scanUnsignedInt(const string s, int& index){
        int before = index;
        while (index != s.size() && s[index] >= '0' && s[index] <= '9')
        {
            ++index;
        }
        return index > before;
    }
public:
    bool isNumber(string s) {
        if (s.size() == 0)
        {
            return false;
        }
        // 从非空格地方开始检查
        int index = 0;
        while (s[index] == ' ')
        {
            ++index;
        }
        bool numeric = scanInt(s, index);
        // .形式的小数
        if (s[index] == '.')
        {
            ++index;
            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            // 因为.形式的小数后面应该是无符号的整数了，所以此处的判断用scanUnsignedInt
            numeric = scanUnsignedInt(s, index) || numeric;
        }
        // 含 e || E 形式的小数
        if (s[index] == 'e' || s[index] == 'E')
        {
            ++index;
            // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            // 因为科学计数法形式的小数后面的数可能为正或负，所以此处的判断用scanInt
            numeric = scanInt(s, index) && numeric;
        }
        while (s[index] == ' ')
        {
            ++index;
        }
        return index == s.size() && numeric;
    }
};