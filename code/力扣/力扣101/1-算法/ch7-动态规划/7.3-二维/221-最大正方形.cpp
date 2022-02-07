/*
在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), length = 0;
        vector<vector<int>> ans(m, vector<int>(n, 0));        
        if (m ==0 || n == 0)
        {
            return 0;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (matrix[i][i] == '0')
                {
                    ans[i][j] == 0;
                }
                else
                {
                    ans[i][j] = min(ans[i - 1][j - 1], min(ans[i - 1][j], ans[i][j - 1])) + 1;
                }
                length = max(ans[i][j], length);
            }
            
        }
        return length * length;
    }
};