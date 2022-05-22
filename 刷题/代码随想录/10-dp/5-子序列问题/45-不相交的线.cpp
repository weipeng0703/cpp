/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-21 09:12:35
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-22 22:18:39
 */
/*
力扣1035. 不相交的线
在两条独立的水平线上按给定的顺序写下 nums1 和 nums2 中的整数。
现在，可以绘制一些连接两个数字 nums1[i] 和 nums2[j] 的直线，这些直线需要同时满足满足：
    nums1[i] == nums2[j]
    且绘制的直线不与任何其他连线（非水平线）相交。
    请注意，连线即使在端点也不能相交：每个数字只能属于一条连线。

以这种方法绘制线条，并返回可以绘制的最大连线数。

示例 1：
    输入：nums1 = [1,4,2], nums2 = [1,2,4]
    输出：2
    解释：可以画出两条不交叉的线，如上图所示。 
    但无法画出第三条不相交的直线，因为从 nums1[1]=4 到 nums2[2]=4 的直线将与从 nums1[2]=2 到 nums2[1]=2 的直线相交。
示例 2：
    输入：nums1 = [2,5,1,2,5], nums2 = [10,5,2,1,5,2]
    输出：3
示例 3：
    输入：nums1 = [1,3,7,1,7,5], nums2 = [1,9,2,5,1]
    输出：2
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

// 思路：
// 求两个序列中相等的数字，而且还不能相交
// 画图可以看出，只要保证两个序列中相等的数字的相对顺序不变即可
// 这样问题就转换成了T44-求两个序列中最长的公共子序列长度（一模一样）

// 1. dp
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() == 0 || nums2.size() == 0) return 0;
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int ans = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};