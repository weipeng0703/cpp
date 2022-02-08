/*
已知字母 A-Z 可以表示成数字 1-26。给定一个数字串，求有多少种不同的字符串等价于这个
数字串。

示例 1：
    Input: "226"
    Output: 3
    解释：有三种解码方式：BZ(2 26)、VF(22 6) 或 BBF(2 2 6)。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.DP
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0)
        {
            return 0;
        }
        vector<int> ans(n + 1, 0);
        ans[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            // 因为i表示的是结果数组的第几位，对应于字符串中要-1
            if (s[i - 1] != '0')
            {
                ans[i] += ans[i - 1];
            }
            if (i > 1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + s[i - 1] <= 26))
            {
                ans[i] += ans[i - 2];
            }
        }
        return ans[n];
    }
};