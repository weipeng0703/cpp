/*
力扣-8. 字符串转换整数 (atoi)
请你来实现一个 myAtoi(string s) 函数，
使其能将字符串转换成一个 32 位有符号整数（类似 C/C++ 中的 atoi 函数）。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.按部就班
class Solution {
public:
    int myAtoi(string s) {
        // flag初始一定要设置为1
        int res = 0, flag = 1, i = 0, n = s.length();
        // 这个循环的方式一定要记住
        while (s[i++] == ' ');
        i--;
        // 退回到符号位
        // 开始判断正负
        // i--;
        if (i < n && (s[i] == '+' || s[i] == '-'))
        {
            flag = (s[i] == '+'? 1 : -1);
            i++;
        }
        // 处理数字
        for (; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && (s[i] - '0' > 7))
                {
                    return (flag + 1 == 0)? INT_MIN : INT_MAX;
                }
                res = res * 10 + (s[i] - '0');
            }
            // 其他字符
            else
            {
                break;
            }
            
        }
        return res * flag;
    }
};
// 2.投机取巧法
class Solution
{
public:
    int myAtoi(string str)
    {
        int res = 0;
        stringstream ss(s);
        ss >> res;
        return res;
    }
};

