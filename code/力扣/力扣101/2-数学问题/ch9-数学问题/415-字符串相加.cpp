/*
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

示例 1：

    输入：num1 = "11", num2 = "123"
    输出："134"
示例 2：

    输入：num1 = "456", num2 = "77"
    输出："533"
示例 3：

    输入：num1 = "0", num2 = "0"
    输出："0"
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 双指针模拟两个大整数相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        while (i >= 0 || j >= 0 || add != 0)
        {
            // 用两个字符之间的距离表示数字
            int x = (i >= 0)? num1[i] - '0' : 0;
            int y = (j >= 0)? num2[j] - '0' : 0;

            int res = x + y + add;
            // 将数字转换为string内的形式
            ans.push_back('0' + res % 10);
            add = res / 10;

            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};