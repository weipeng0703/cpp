/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-01 08:53:47
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-01 10:20:49
 */
/*
力扣T-200. 岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1：
    输入：grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
    ]
    输出：1
示例 2：
    输入：grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
    ]
    输出：3
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

// 1-深搜
class Solution {
public:
    void dfs (vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1')  {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }
};

// 2-广搜
class Solution {
public:
    void dfs (vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        if (i - 1 >= 0 && grid[i - 1][j] == '1') dfs(grid, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == '1') dfs(grid, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == '1') dfs(grid, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == '1') dfs(grid, i, j + 1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto temp = q.front();
                        q.pop();
                        int row = temp.first, col = temp.second;
                        if (row - 1 >= 0 && grid[row - 1][col] == '1') {
                            q.push({row - 1, col});
                            grid[row - 1][col] = '0';
                        }
                        if (row + 1 < grid.size() && grid[row + 1][col] == '1') {
                            q.push({row + 1, col});
                            grid[row + 1][col] = '0';
                        }
                        if (col - 1 >= 0 && grid[row][col - 1] == '1') {
                            q.push({row, col - 1});
                            grid[row][col - 1] = '0';
                        }
                        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1') {
                            q.push({row, col + 1});
                            grid[row][col + 1] = '0';
                        }
                    }
                }
            }
        }
        return ans;
    }
};