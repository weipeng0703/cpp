/*
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

示例 1：
    输入：m = 2, n = 3, k = 1
    输出：3
示例 2：
    输入：m = 3, n = 1, k = 0
    输出：1
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
using namespace std; 

// DFS
class Solution {
public:
    // 求某数数位之和
    int sum(int x, int y){
        // 一定一定一定要注意，变量初始化一定要初始化为0啊，要不然会出现意想不到的莫名其妙的结果
        // 一定一定一定要注意，变量初始化一定要初始化为0啊，要不然会出现意想不到的莫名其妙的结果
        // 一定一定一定要注意，变量初始化一定要初始化为0啊，要不然会出现意想不到的莫名其妙的结果
        int ans = 0;
        while (x > 0)
        {
            ans += x % 10;
            x /= 10;
        }
        while (y > 0)
        {
            ans += y % 10;
            y /= 10;
        }
        return ans;
    }
    int dfs(vector<vector<bool>>& temp, int m, int n, int i, int j, int k){
        if (i >= m || j >= n || sum(i, j) > k || temp[i][j] == true){
            return 0;
        }
        // 将该位置标记为访问过
        temp[i][j] = true;
        // 只需向下或向右移动
        return 1 + dfs(temp, m, n, i + 1, j, k) + dfs(temp, m, n, i, j + 1, k);
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n));
        return dfs(visited, m, n, 0, 0, k);
    }
};