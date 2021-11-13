/*
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。

示例 1:
    输入: a = "11", b = "1"
    输出: "100"
示例 2:
    输入: a = "1010", b = "1011"
    输出: "10101"

提示：
    每个字符串仅由字符 '0' 或 '1' 组成。
    1 <= a.length, b.length <= 10^4
    字符串如果不是 "0" ，就都不含前导零。
*/
#include<string>
#include<math.h>
#include<vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int length_a = a.size();
        int length_b = b.size();

        while (length_a < length_b)
        {
            a = '0' + a;
            length_a++;
        }
        while (length_a > length_b)
        {
            b = '0' + b;
            length_b++;
        }

        int carry = 0;   // 进位用的标志

        for (int i = length_a - 1; i >= 0; i--)
        {
            // ASC码48就是'0'，也就是说'0'的值是48，而后依次是'1'到'9'。 这样正好是char型减去48就是它对应的int值。
            int sum = a[i] - '0' + b[i] - '0' + carry;
            a[i] = (sum % 2) + '0';    // 与上面同理，将int类型转化为char型
            carry = sum / 2;
        }   
        if (carry > 0)   // 若有溢出
        {
            a = '1' + a;
            return a;
        }
    }
};