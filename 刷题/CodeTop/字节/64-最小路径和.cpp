/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-31 22:35:45
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-31 22:47:58
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
#include<queue>
using namespace std;
/*
力扣T-64. 最小路径和
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例1：
    输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
    输出：7
    解释：因为路径 1→3→1→1→1 的总和最小。
示例 2：
    输入：grid = [[1,2,3],[4,5,6]]
    输出：12
*/ 
// 1-自写dp
// 到达nums[i][j]的最近距离 dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + nums[i][j];
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for (int i = 1; i < n; i++) dp[0][i] = dp[0][i - 1] + grid[0][i];
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};