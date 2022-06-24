/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-23 21:45:29
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-24 09:40:24
 */
/*
力扣T684. 冗余连接
树可以看成是一个连通且 无环 的 无向 图。
给定往一棵 n 个节点 (节点值 1～n) 的树中添加一条边后的图。
添加的边的两个顶点包含在 1 到 n 中间，且这条附加的边不属于树中已存在的边。
图的信息记录于长度为 n 的二维数组 edges ，edges[i] = [ai, bi] 表示图中在 ai 和 bi 之间存在一条边。
请找出一条可以删去的边，删除后可使得剩余部分是一个有着 n 个节点的树。如果有多个答案，则返回数组 edges 中最后出现的边。

示例 1：
    输入: edges = [[1,2], [1,3], [2,3]]
    输出: [2,3]
示例 2：
    输入: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
    输出: [1,4]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.并查集

/*
从前向后遍历每一条边，边的两个节点如果不在同一个集合，就加入集合（即：同一个根节点）。
如果边的两个节点已经出现在同一个集合里，说明这两个节点已经连在一起了，如果再加入这条边一定就出现环了，
所以这条边不能加入集合，即删除这条边
*/

class Solution {
public:
    int n = 1005; // 节点数量 3 到 1000
    int father[1005];

    // 并查集初始化
    void init() {
        for (int i = 0; i < n; ++i) father[i] = i;
    }
    // 并查集里寻根的过程
    int find(int u) {
        if (u != father[u]) father[u] = find(father[u]);
        // else father[u] = u;      // 相等的话这一步省略即可，因为最终返回father[u]即为u
        return father[u];
    }
    // 将v->u 这条边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // 判断 u 和 v 是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        init ();
        for (int i = 0; i < edges.size(); i++) {
            if (same(edges[i][0], edges[i][1])) return edges[i];
            else join(edges[i][0], edges[i][1]);
        }
        return {};
    }
};

