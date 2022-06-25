/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-25 22:03:03
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-25 22:24:31
 */
/*
力扣T463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。
整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。
网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

示例 1：
    输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
    输出：16
    解释：它的周长是上面图片中的 16 个黄色的边
示例 2：
    输入：grid = [[1]]
    输出：4
示例 3：
    输入：grid = [[1,0]]
    输出：4
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1. 计算出总的岛屿数量，因为有一对相邻两个陆地，边的总数就减2，那么在计算出相邻岛屿的数量就可以了。
// result = 岛屿数量 * 4 - cover * 2;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;
        int count = 0;          // 相邻陆地数量
        int countOne = 0;       // 陆地数量
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1)  {
                countOne++;
                // 对于一块岛屿，统一只统计上边相邻陆地
                if (i - 1 >= 0 && grid[i -1][j] == 1) count++;
                // 对于一块岛屿，统一只统计左边相邻陆地
                if (j - 1 >= 0 && grid[i][j - 1] == 1) count++;
                // 不统计下边和右边相邻陆地了，防止重复
                }
            }
        }
        return 4 * countOne - 2 * count;
    }
};