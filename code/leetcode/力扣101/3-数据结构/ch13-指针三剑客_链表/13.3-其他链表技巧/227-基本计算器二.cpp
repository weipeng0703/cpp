/*
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。

示例 1：
    输入：s = "3+2*2"
    输出：7
示例 2：
    输入：s = " 3/2 "
    输出：1
示例 3：
    输入：s = " 3+5 / 2 "
    输出：5
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.思路
/*
由于乘除优先于加减计算，因此不妨考虑先进行所有乘除运算，
并将这些乘除运算后的整数值放回原表达式的相应位置，
则随后整个表达式的值，就等于一系列整数加减后的值。

基于此，我们可以用一个栈保存这些（进行乘除运算后的）整数的值。
对于加减号后的数字，将其直接压入栈中；
对于乘除号后的数字，可以直接与栈顶元素计算，并替换栈顶元素为计算后的结果。

具体来说，遍历字符串 s，并用变量 preSign 记录每个数字之前的运算符，
对于第一个数字，其之前的运算符视为加号。
每次遍历到数字末尾时，根据 preSign 来决定计算方式：
    加号：将数字压入栈；
    减号：将数字的相反数压入栈；
    乘除号：计算数字与栈顶元素，并将栈顶元素替换为计算结果。
代码实现中，若读到一个运算符，或者遍历到字符串末尾，即认为是遍历到了数字末尾。
处理完该数字后，更新 preSign 为当前遍历的字符。

遍历完字符串 ss 后，将栈中元素累加，即为该字符串表达式的值。
*/
class Solution {
public:
    int calculate(string s) {
        vector<int> results;        // 存储操作过的数字
        char presign = '+';         // 首字符默认为+
        int size = s.size();
        int num = 0;                // 当前要处理的数字

        for (int i = 0; i < size; i++)
        {
            // isdigit()判断当前字符是否为数字
            if (isdigit(s[i]))     // 计算一段连续数字是几
            {
                num = num * 10 + int(s[i] - '0');
            }
            // 注意运算优先级 ! > && > ||
            if ((!isdigit(s[i]) && s[i] != ' ') || i == size - 1)
            {
                // 此处的presign为当前数字之前的符号
                // 选择结构中操作的数字num为当前经过isdigit(i)处理后的数字
                switch (presign)
                {
                case '+':
                    results.push_back(num);
                    break;
                case '-':
                    results.push_back(-num);
                    break;
                case '*':
                    results.back() *= num;
                    break;
                default:
                    results.back() /= num;
                }
                presign = s[i];     // 下一个数字前的字母
                num = 0;            // 将已经处理完的数字归零，重新计算下一个数字
        }
    }
    // accumulate带有三个形参：头两个形参指定要累加的元素范围，第三个形参则是累加的初值。
    return accumulate(results.begin(), results.end(), 0);
    }
};