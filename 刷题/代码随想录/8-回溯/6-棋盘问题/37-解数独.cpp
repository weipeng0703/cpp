/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-28 16:30:29
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-28 17:13:07
 */
/*
力扣37. 解数独
编写一个程序，通过填充空格来解决数独问题。
数独的解法需 遵循如下规则：
    数字 1-9 在每一行只能出现一次。
    数字 1-9 在每一列只能出现一次。
    数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

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
    bool isValid(int row, int col, char ch, vector<vector<char>>& board) {
        // 行 <9 是因为空格中某个位置的上下左右可能有预先填充的数据
        for (int i = 0; i < 9; i++){
            if (board[row][i] == ch) return false;
        }
        // 列
        for (int i = 0; i < 9; i++){
            if (board[i][col] == ch) return false;
        }
        // 宫内
        // 使用 (当前数/规定行数) * 规定行数 的方式求当前数应处于的范围
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == ch) return false;
            }
        }
        return true;
    }
    // 二维回溯
    bool backtrack(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') continue;       // 跳过已有数字的位置
                for (char k = '1'; k <= '9'; k++) {     // 判断当前位置应该填入己
                    if (isValid(i, j, k, board)) {
                        board[i][j] = k;
                        if (backtrack(board)) return true;
                        board[i][j] = '.';
                    } 
                }
                // 若9个数字都试完了发现都不符合，返回false无解
                return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};