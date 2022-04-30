/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢 

示例 1：
    输入：n = 2
    输出：2
    解释：有两种方法可以爬到楼顶。
    1. 1 阶 + 1 阶
    2. 2 阶
示例 2：
    输入：n = 3
    输出：3
    解释：有三种方法可以爬到楼顶。
    1. 1 阶 + 1 阶 + 1 阶
    2. 1 阶 + 2 阶
    3. 2 阶 + 1 阶
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
    int climbStairs(int n) {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        
        vector<int> ans(n + 1, 0);
        ans[0] = 0;
        ans[1] = 1;
        ans[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            ans[i] = ans[i - 1] + ans[i - 2]; 
        }
        return ans[n];
    }
};
// 2.DP+压缩空间
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
        {
            return n;
        }
        int n1 = 1, n2 = 2, ans;
        for(int i = 3; i <= n; i++)
        {
            ans = n1 + n2;
            n1 = n2;
            n2 = ans;
        }
        return ans;
    }
};