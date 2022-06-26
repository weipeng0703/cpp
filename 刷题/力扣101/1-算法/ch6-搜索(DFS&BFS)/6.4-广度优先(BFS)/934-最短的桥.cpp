/*
在给定的二维二进制数组 A 中，存在两座岛。（岛是由连续的 1 形成的一个最大组。）
现在，我们可以将 0 变为 1，以使两座岛连接起来，变成一座岛。
返回必须翻转的 0 的最小数目。（可以保证答案至少是 1 。）

示例 1：
    输入：A = [[0,1],[1,0]]
    输出：1
示例 2：
    输入：A = [[0,1,0],[0,0,0],[0,0,1]]
    输出：2
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.深搜+广搜
// 本题实际上是求两个岛屿间的最短距离，因此我们可以先通过任意搜索方法(常用深搜)找到其中一个岛
// 屿，然后利用广度优先搜索，查找其与另一个岛屿的最短距离。
class Solution {
private:
    // 辅助数组
    vector<int> direction{-1, 0, 1, 0, -1};
public:
    // 深搜的辅助函数
    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, 
            int m, int n, int i, int j)
            {
                if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 2)
                {
                    return;
                }
                if (grid[i][j] == 0)
                {
                    points.push({i, j});
                    return;
                }
                grid[i][j] == 2;
                dfs(points, grids, m, n, i + 1, j);
                dfs(points, grids, m, n, i - 1, j);
                dfs(points, grids, m, n, i, j + 1);
                dfs(points, grids, m, n, i, j - 1);
            }
    // 主函数
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;

        // dfs寻找第一个岛屿,并将其1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; i++)
        {
            if (flipped == true)
            {
                break;
            }
            for (int j = 0; j < n; i++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grids, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿,将过程中经过的0赋值为2
        int x, y;
        int level = 0;
        while (!points.empty())
        {
            // 路过一个points中的点代表路线+1
            ++level;
            int points_num = points.size();
            while (points_num--)
            {
                auto [r, c] = points.front();
                points.pop();

                for (int k = 0; k < 4; k++)
                {
                    // 将grid[i][j] == 0(即非路线的点)的点分别加上k中的数字
                    // 实现其上移,右移,下移,左移的广度搜索
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 || x < m || y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            // 到达另一座桥了,输出经过的路线level
                            return level;
                        }
                        // 将grid[x][y] == 0的点放进去搜索
                        points.push({x, y});
                        grid[x][y] == 2;
                    }   
                }   
            }
        }
    }
};


// 1.深搜+广搜
// 本题实际上是求两个岛屿间的最短距离，因此我们可以先通过任意搜索方法(常用深搜)找到其中一个岛
// 屿，然后利用广度优先搜索，查找其与另一个岛屿的最短距离。
class Solution {
public:
    // 深搜的辅助函数
    void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, 
            int m, int n, int i, int j)
            {
                if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2)
                {
                    return;
                }
                if (grid[i][j] == 0)
                {
                    points.push({i, j});
                    return;
                }
                grid[i][j] = 2;
                dfs(points, grid, m, n, i - 1, j);
                dfs(points, grid, m, n, i + 1, j);
                dfs(points, grid, m, n, i, j - 1);
                dfs(points, grid, m, n, i, j + 1);
            }
    // 主函数
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        vector<int> direction{-1, 0, 1, 0, -1};
        // dfs寻找第一个岛屿,并将其1全部赋值为2
        bool flipped = false;
        for (int i = 0; i < m; ++i)
        {
            if (flipped == true)
            {
                break;
            }
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 1)
                {
                    dfs(points, grid, m, n, i, j);
                    flipped = true;
                    break;
                }
            }
        }
        // bfs寻找第二个岛屿,将过程中经过的0赋值为2
        int x, y;
        int level = 0;
        while (!points.empty())
        {
            // 路过一个points中的点代表路线+1
            ++level;
            int points_num = points.size();
            while (points_num--)
            {
                auto [r, c] = points.front();
                points.pop();

                for (int k = 0; k < 4; ++k)
                {
                    // 将grid[i][j] == 0(即非路线的点)的点分别加上k中的数字
                    // 实现其上移,右移,下移,左移的广度搜索
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if (x >= 0 && y >= 0 || x < m || y < n)
                    {
                        if (grid[x][y] == 2)
                        {
                            continue;
                        }
                        if (grid[x][y] == 1)
                        {
                            // 到达另一座桥了,输出经过的路线level
                            return level;
                        }
                        // 将grid[x][y] == 0的点放进去搜索
                        points.push({x, y});
                        grid[x][y] = 2;
                    }   
                }   
            }
        }
        return 0;
    }
};