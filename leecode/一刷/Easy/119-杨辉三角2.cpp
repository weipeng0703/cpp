/*
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。
在「杨辉三角」中，每个数是它左上方和右上方的数的和。

示例 1:
    输入: rowIndex = 3
    输出: [1,3,3,1]
示例 2:
    输入: rowIndex = 0
    输出: [1]

0 <= rowIndex <= 33
*/
#include<vector>
using namespace std;

// 借用上题的思路
class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<vector<int>> res(rowIndex + 1);   // 因为rowIndex是从0开始
        
        for (int i = 0; i <= rowIndex ; i++)
        {
            res[i].resize(i + 1);                 // 因为rowIndex是从0开始
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; j++)
            {
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }    
        }
        
        return res[rowIndex];
    }
};