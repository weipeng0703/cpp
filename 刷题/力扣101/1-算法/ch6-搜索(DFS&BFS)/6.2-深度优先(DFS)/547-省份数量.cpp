/*
有 n 个城市，其中一些彼此相连，另一些没有相连。
如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。

省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 
表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。

返回矩阵中 省份 的数量（注意 不是省的数量）。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;
// 1.深度优先搜索
class Solution {
public:
    // 一定要注意，visited数组要使用引用，因为要随时准备修改它
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int n, int i)
    {
        for (int j = 0; j < n; j++)
        {
            // 对于与城市i相邻的城市j，如果他们还未被访问
            if (isConnected[i][j] == 1 && visited[j] == 0)
            {
                // 将他们标记为已经被访问
                visited[j] = 1;
                // 深度搜索，对城市i相邻的j城市继续搜索
                dfs(isConnected, visited, n, j);
            }
            
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        if (n == 0)
        {
            return 0;
        }
        int count = 0;
        vector<int> visited (n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])    // 若该城市还未被访问
            {
                dfs(isConnected, visited, n, i);
                count++;
            }
        }
        return count;
    }
};
// 空间复杂度：
// O(n)，其中 n 是城市的数量。需要使用数组 visited 记录每个城市是否被访问过，
// 数组长度是 n，递归调用栈的深度不会超过 n。
// 时间复杂度：
// O(n的平方)，其中 n 是城市的数量。需要遍历矩阵 n 中的每个元素。

class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int provinces, int i) {
        for (int j = 0; j < provinces; j++) {
            if (isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = 1;
                dfs(isConnected, visited, provinces, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = isConnected.size();
        vector<int> visited(provinces);
        int circles = 0;
        for (int i = 0; i < provinces; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, provinces, i);
                circles++;
            }
        }
        return circles;
    }
};

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/number-of-provinces/solution/sheng-fen-shu-liang-by-leetcode-solution-eyk0/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。