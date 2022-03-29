/*
力扣59.螺旋矩阵(2)
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
    输入：n = 3
    输出：[[1,2,3],[8,9,4],[7,6,5]]
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
// 1.模拟
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n == 0) return res;

        vector<vector<int>> ans(n, vector<int>(n, 0));
        // 定义上下左右端点
        // 注意，如果将down和right设置为n的话，下面ans[i][right]和ans[down][i]会出错，
        // 所以还是设置为左右闭的区间方便一些
        int top = 0, down = n - 1, left = 0, right = n - 1;
        
        // 起始数据
        int k = 1;
        while (k <= n * n)
        {
            // 从左到右,[不变][变]，循环结束后，左边[]++
            for (int i = left; i <= right; ++i, ++k) ans[top][i] = k;
            // 下面一行
            ++top;
            // 从上到下,[变][不变]，循环结束后，右边[]--
            for (int i = top; i <= down; ++i, ++k) ans[i][right] = k;
            // 左边一列
            --right;
            // 从右到左,[不变][变]，循环结束后，左边[]--
            for (int i = right; i >= left; --i, ++k) ans[down][i] = k;
            // 上面一行
            --down;
            // 从下到上,[变][不变]，循环结束后，右边[]++
            for (int i = down; i >= top; --i, ++k) ans[i][left] = k;
            // 右边一列
            ++left;
        }
        return ans;
    }
};