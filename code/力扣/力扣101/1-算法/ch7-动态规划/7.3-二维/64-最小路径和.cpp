/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，
使得路径上的数字总和为最小。
说明：每次只能向下或者向右移动一步。

示例 1：
    输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
    输出：7
    解释：因为路径 1→3→1→1→1 的总和最小。
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
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0)
        {
            return 0;
        }
        vector<vector<int>> temp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                {
                    temp[i][j] = grid[0][0];
                }
                else if (i == 0)
                {
                    // 在第一行的话只能是从他左边过来的
                    temp[i][j] = grid[i][j] + temp[i][j - 1];
                }
                else if (j == 0)
                {
                    // 在第一列的话只能是从他上边过来的
                    temp[i][j] = grid[i][j] + temp[i - 1][j];
                }
                else
                {
                    temp[i][j] = grid[i][j] + min(temp[i - 1][j], temp[i][j - 1]);
                }
                
            }
            
        }
        return temp[m - 1][n - 1];
    }
};