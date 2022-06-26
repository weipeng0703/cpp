/*
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.回溯法

// 外层：遍历
// 首先遍历 board 的所有元素，先找到和 word 第一个字母相同的元素，然后进入递归流程。
// 假设这个元素的坐标为 (i, j)，进入递归流程前，先记得把该元素打上使用过的标记：mark[i][j] = 1

// 内层：递归
// 好了，打完标记了，现在我们进入了递归流程。递归流程主要做了这么几件事：
// 从 (i, j) 出发，朝它的上下左右试探，看看它周边的这四个元素是否能匹配 word 的下一个字母
// 如果匹配到了：带着该元素继续进入下一个递归
// 如果都匹配不到：返回 False

// 当 word 的所有字母都完成匹配后，整个流程返回 True

class Solution {
public:
    void backtrack(int i, int j, vector<vector<char>>& board, string& world, 
                bool flag, vector<vector<int>>& visited, int pos)
            {
                if (i < 0 || i > board.size() || j < 0 || j > board[0].size())
                {
                    return;
                }
                if (visited[i][j] == 1 || find || board[i][j] != string[pos])
                {
                    return;
                }
                if (pos == word.size() - 1)
                {
                    flag = true;
                    return;
                }
                visited[i][j] == 1;
                backtrack(i - 1, j, board, word, flag, visited, pos + 1);
                backtrack(i + 1, j, board, word, flag, visited, pos + 1);
                backtrack(i, j + 1, board, word, flag, visited, pos + 1);
                backtrack(i, j + 1, board, word, flag, visited, pos + 1);
                visited[i][j] == 0;
            }
                    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if (m == 0)
        {
            return false;
        }
        vector<vector<int>> visited(m, vector<int>(n, 0));
        bool flag = false;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                backtrack(i, j, board, word, flag, visited, 0);
            }
        }
        return flag;
    }
};