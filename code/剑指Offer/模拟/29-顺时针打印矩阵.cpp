/*
同力扣T54. 螺旋矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

示例 1：
    输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    输出：[1,2,3,6,9,8,7,4,5]
示例 2:
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
// #include<unordered_map>
using namespace std; 
// 螺旋遍历+调整边界
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
        {
            return ans;
        }
        // 定义上下左右边界
        int upper = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        while (true)
        {   
            // 向右遍历
            for (int i = left; i <= right; ++i){
                ans.push_back(matrix[upper][i]);
            }
            if(++upper > down) break;
            // 向下遍历
            for (int k = upper; k <= down; ++k){
                ans.push_back(matrix[k][right]);
            }
            if(--right < left) break;
            // 向左遍历
            for (int m = right; m >= left; --m){
                ans.push_back(matrix[down][m]);
            }
            if(--down < upper) break;
            // 向上遍历
            for (int n = down; n >= upper; --n){
                ans.push_back(matrix[n][left]);
            }
            if(++left > right) break;
        }
        return ans;
    }
};