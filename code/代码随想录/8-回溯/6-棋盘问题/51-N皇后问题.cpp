/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-27 19:07:21
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-28 16:00:32
 */
/*
力扣51. N 皇后
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
彼此不能攻击的条件：任意两个皇后不能同行，同列，同斜线
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
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

class Solution {
public:
    vector<vector<string>> ans;

    void backtrack(int n, int row, vector<string>& path) {
        if (row == n) {
            ans.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (isValid(row, col, path, n)) {
                path[row][col] = 'Q';
                backtrack(n, row + 1, path);
                path[row][col] = '.';
            }
        }
    }
    // 判断当前放入棋盘的皇后是否合法
    bool isValid(int row, int col, vector<string>& path, int n) {
        // 判断行
        for (int i = 0; i < col; i++) {
            if (path[row][i] == 'Q') return false;
        }
        // 判断列
        for (int i = 0; i < row; i++) {
            if (path[i][col] == 'Q') return false;
        }
        // 检查45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (path[i][j] == 'Q') return false;
        }
        // 检查135度角是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (path[i][j] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return ans;
        // 1.初始化一个路径数组，其元素为n行n列的.
        vector<string> path(n, string(n, '.'));
        // 2.回溯判断是否将.变为Q
        backtrack(n, 0, path);
        return ans;
    }
};