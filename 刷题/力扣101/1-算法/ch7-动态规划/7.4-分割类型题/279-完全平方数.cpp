/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。
例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
    输入：n = 12
    输出：3 
    解释：12 = 4 + 4 + 4
示例 2：
    输入：n = 13
    输出：2
    解释：13 = 4 + 9
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
    int numSquares(int n) {
        if (n == 0)
        {
            return 0;
        }
        vector<int> ans(n + 1, INT_MAX);
        ans[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                ans[i] = min(ans[i], ans[i - j * j] + 1);
            }
        }
        return ans[n];
    }
};