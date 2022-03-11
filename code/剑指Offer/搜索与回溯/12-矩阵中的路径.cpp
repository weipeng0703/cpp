/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

示例 1：
    输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
    输出：true
示例 2：
    输入：board = [["a","b"],["c","d"]], word = "abcd"
    输出：false 
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
// DFS+剪枝
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0){
            return false;
        }
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
private:
    int m, n;
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k){
        if (i >= m || i < 0 || j >= n || j < 0 || board[i][j] != word[k]){
            return false;
        }
        if (k == word.size() - 1){
            return true;
        }
        // 将已经搜索过的矩阵中元素置空，防止重复搜索
        board[i][j] = '\0';
        // 搜索其他地方:按照下右上左的方向
        bool res = dfs(board, word, i + 1, j, k + 1) || dfs(board, word, i, j + 1, k + 1) ||
                   dfs(board, word, i - 1, j, k + 1) || dfs(board, word, i, j - 1, k + 1);
        // 绕word[k]搜索完之后，将其还原，因为可能之后其他字母的搜索中要用它
        board[i][j] = word[k];
        return res;
    }
};