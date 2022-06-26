/*
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，
其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。

示例 1：
    输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
    输出：[[0,0,0],[0,1,0],[0,0,0]]
示例 2：
    输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
    输出：[[0,0,0],[0,1,0],[1,2,1]]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.DP
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // 注意最初的ans矩阵元素设置为最大值
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX - 1));
        
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    ans[i][j] = 0;
                }
                else
                {
                    if (j > 0)
                    {
                        ans[i][j] = min(ans[i][j], ans[i][j - 1] + 1);
                    }
                    if (i > 0)
                    {
                        ans[i][j] = min(ans[i][j], ans[i - 1][j] + 1);
                    }
                }
            }
        }
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if(mat[i][j] != 0)
                {
                    if (j < n - 1)
                    {
                        ans[i][j] = min(ans[i][j], ans[i][j + 1] + 1);
                    }
                    if (i < m - 1)
                    {
                        ans[i][j] = min(ans[i][j], ans[i + 1][j] + 1);
                    }
                }
            }
        }
        return ans;
    }
};