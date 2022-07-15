/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-15 20:17:29
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-15 20:49:04
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
/*
力扣-48. 旋转图像
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

示例 1：
    输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
    输出：[[7,4,1],[8,5,2],[9,6,3]]
示例 2：
    输入：matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
    输出：[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
*/ 

// 1. 输入队列中再从上到下从右往左填充
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        queue<int> q;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix.size(); j++) {
                q.push(matrix[i][j]);
            }
        }
        for (int j = matrix.size() - 1; j >= 0; j--) {
            for (int i = 0; i < matrix.size(); i++) {
                int temp = q.front();
                q.pop();
                matrix[i][j] = temp;
            }
        }
    }
};
// 2-先水平翻转后对角线翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        // 对于每一行
        for (int i = 0; i < n / 2; i++)  {
            // 对于每一行的所有数字
            for (int j = 0; j < n; j++) swap(matrix[i][j], matrix[n - i - 1][j]);
        }
        // 主对角线翻转
        // 对于每一行
        for (int i = 0; i < n; i++) {
            // 对于每一行对角线数字之前的数字
            for (int j = 0; j < i; j++) swap(matrix[i][j], matrix[j][i]);
        }
    }
};
// 3-原地翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int temp = 0, n = matrix.size()-1;
        for (int i = 0; i <= n / 2; ++i) {
            for (int j = i; j < n - i; ++j) {
                // 对四个位置的数进行交换
                temp = matrix[j][n-i];
                matrix[j][n-i] = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = temp;
            } 
        } 
    }
};