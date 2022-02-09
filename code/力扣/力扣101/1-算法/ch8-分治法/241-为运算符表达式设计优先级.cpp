/*
给定一个只包含加、减和乘法的数学表达式，求通过加括号可以得到多少种不同的结果。
输入是一个字符串，表示数学表达式；输出是一个数组，存储所有不同的加括号结果。

示例 1：
   Input: "2-1-1"
    Output: [0, 2]
    在这个样例中，有两种加括号结果：((2-1)-1) = 0 和 (2-(1-1)) = 2。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.递归分治法
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        if (string.empty())
        {
            return ans;
        }
        for (int i = 0; i < expression.length(); i++)
        {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                for (const int& l : left)
                {
                    for (const int& r : right)
                    {
                        switch (c)
                        {
                        case '+':
                            ans.push_back(l + r);
                            break;
                        case '-':
                            ans.push_back(l - r);
                            break;
                        case '*':
                            ans.push_back(l * r);
                            break;
                    }
                }
            }
        }
    }
    if (ans.empty())
    {
        // stoi()将 n 进制的字符串转化为十进制，在头文件<string>中
        ans.push_back(stoi(expression));
    }
    return ans;
    }
};