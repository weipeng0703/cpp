/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图像。

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:原地翻转
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


// 方法二：先水平翻转，后主对角线翻转
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 水平翻转
        // 对于每一行
        for (int i = 0; i < n / 2; i++) 
        {
            // 对于每一行的所有数字
            for (int j = 0; j < n; j++)
            {
                swap(matrix[i][j], matrix[n - i - 1][j]);
            }
            
        }
        // 主对角线翻转
        // 对于每一行
        for (int i = 0; i < n; i++)
        {
            // 对于每一行对角线数字之前的数字
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
            
        }

    }
};
