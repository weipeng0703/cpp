/*
给你一个大小为 m x n 的二进制矩阵 grid 。
岛屿 是由一些相邻的 1 (代表土地) 构成的组合，
这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。
岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.深度优先搜索
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
        {
            return 0;
        }
        // 为了确保每个土地访问不超过一次，我们每次经过一块土地时，将这块土地的值置为 0。
        // 这样就不会多次访问同一土地。
        grid[i][j] = 0;
        return 1 + dfs(grid, i, j - 1) + dfs(grid, i, j + 1) + 
                dfs(grid, i - 1, j) + dfs(grid, i + 1, j);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n == 0)
        {
            return 0;
        }
        int ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
// 空间复杂度：递归时，最大情况是递归深度为整个网络的大小，所以为O(行数*列数)
// 时间复杂度：递归时，最大情况是递归深度为整个网络的大小，每个节点都要访问一次，
//     所以为O(行数*列数)