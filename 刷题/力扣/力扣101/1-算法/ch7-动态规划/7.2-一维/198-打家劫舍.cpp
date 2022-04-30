/*
你是一个专业的小偷，计划偷窃沿街的房屋。
每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，
计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

示例 1：
    输入：[1,2,3,1]
    输出：4
    解释：偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
         偷窃到的最高金额 = 1 + 3 = 4 。
示例 2：
    输入：[2,7,9,3,1]
    输出：12
    解释：偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
         偷窃到的最高金额 = 2 + 9 + 1 = 12 。
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
    int rob(vector<int>& nums) {
        int s = nums.size();
        if (s == 0)
        {
            return 0;
        }
        vector<int> ans(s + 1, 0);
        ans[0] = 0;
        ans[1] = nums[0];
        for (int i = 2; i <= s; i++)
        {
            // 注意，ans与nums数组i位置上的数字代表的意义是不同的，nums要比ans少一位
            ans[i] = max(ans[i - 1], nums[i - 1] + ans[i - 2]);
        }
        return ans[s];
    }
};
// 2.DP+压缩空间
class Solution {
public:
    int rob(vector<int>& nums) {
        int s = nums.size();
        if (s == 0)
        {
            return 0;
        }
        if (s == 1)
        {
            return nums[0];
        }
        int pre1 = 0, pre2 = 0, ans;
        for (int i = 0; i < s; i++)
        {
            ans = max(pre2, pre1 + nums[i]);
            pre1 = pre2;
            pre2 = ans;
        }
        return ans;
    }
};