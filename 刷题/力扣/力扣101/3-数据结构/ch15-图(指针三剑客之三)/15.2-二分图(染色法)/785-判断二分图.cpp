/*
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。
形式上，对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。
该无向图同时具有以下属性：
    不存在自环（graph[u] 不包含 u）。
    不存在平行边（graph[u] 不包含重复值）。
    如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
    这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：
如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。

示例一：
输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
输出：false
解释：节点0与节点1，2，3相连,节点1与节点0，2相连。。。
不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 利用队列和广度优先搜索，我们可以对未染色的节点进行染色，并且检查是否有颜色相同的相邻节点存在。
// 注意在代码中，我们用 0 表示未检查的节点，用 1 和 2 表示两种不同的颜色。
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 0)
        {
            return true;
        }
        // 构建染色数组记录每个节点的颜色，n个节点最开始均未染色，为0
        vector<int> color(n, 0);
        queue<int> q;

        // 依次对每个节点进行遍历，保证每个节点最后均染上色
        for (int i = 0; i < n; i++)
        {
            if (!color[i])
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                for (const int& j : graph[node])
                {
                    if (color[j] == 0)
                    {
                        q.push(j);
                        color[j] = color[node] == 2? 1 : 2;
                    }
                    else if (color[j] == color[node])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// 染色法，记忆化递归
class Solution {
private:
    bool dfs(const vector<vector<int>> &g, int i, int c, vector<int> &v) {      //返回第i个点染c色能否成功
        if (v[i] != -1) return v[i] == c;                                       //第i个点已染过
        v[i] = c;                                                               //对第i个点染上c色
        for (int j : g[i]) if (!dfs(g, j, !c, v)) return false;                 //递归相邻的点，c => !c 换色
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        const int n = graph.size();
        vector<int> v(n, -1);                                                   //-1表示待染色
        for (int i = 0; i < n; i++) if (v[i] == -1 && !dfs(graph, i, 0, v)) return false;
        return true;
    }
};