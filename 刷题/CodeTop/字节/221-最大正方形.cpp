/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-20 19:29:13
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-20 20:04:21
 */
/*
力扣-221. 最大正方形
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

示例 1：
    输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    输出：4
示例 2：
    输入：matrix = [["0","1"],["1","0"]]
    输出：1
示例 3：
    输入：matrix = [["0"]]
    输出：0
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
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), length = 0;
        vector<vector<int>> ans(m + 1, vector<int>(n + 1, 0));        
        if (m == 0 || n == 0) return 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // if (matrix[i][j] == '0')
                // {
                //     ans[i][j] == 0;
                // }
                if(matrix[i - 1][j - 1] == '1') {
                    ans[i][j] = min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1])) + 1;
                }
                length = max(ans[i][j], length);
            }
        }
        return length * length;
    }
};


