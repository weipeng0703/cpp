/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-10 15:36:10
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-10 16:17:20
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
#include<unordered_map>
#include<priority_queue>
using namespace std;

/*
力扣T-415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。
你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

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

// 1-stoi()+to_string()会越界
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num = stoi(num1) + stoi(num2);
        return to_string(nums);
    }
};
// 2-双指针模拟两个大整数相加
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans = "";
        int i = num1.size() - 1, j = num2.size() - 1, temp = 0;
        // i与j只要有一个没减到0即可继续往下求和 例如11345+234
        // temp>0是为了处理934+843的情况，因为i与j都到0后，还需要处理9+8的进位
        while (i >= 0 || j >= 0 || temp > 0) {
            int x = i >= 0? num1[i] - '0' : 0; 
            int y = j >= 0? num2[j] - '0' : 0; 
            // 求当前位置的数（结果的余数）和需要往前进位的数
            int res = x + y + temp;
            ans.push_back(res % 10 + '0');
            temp = res / 10;
            // 指针左移
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

