/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-02 20:51:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-02 21:45:23
 */
/*
力扣-54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。

示例 1：
    输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    输出：[1,2,3,6,9,8,7,4,5]
示例 2：
    输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
    输出：[1,2,3,4,8,12,11,10,9,5,6,7]
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

// 1. 模拟遍历
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        // 定义上下左右边界
        int upper = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true) {
            // 向右遍历
            for (int i = left; i <= right; i++) ans.push_back(matrix[upper][i]);
            if (++upper > down) break;
            // 向下遍历
            for (int i = upper; i <= down; i++) ans.push_back(matrix[i][right]);
            if (--right < left) break;
            // 向左遍历
            for (int i = right; i >= left; i--) ans.push_back(matrix[down][i]);
            if (--down < upper) break;
            // 向上遍历
            for (int i = down; i >= upper; i--) ans.push_back(matrix[i][left]);
            if (++left > right) break;
        }
        return ans;
    }
};