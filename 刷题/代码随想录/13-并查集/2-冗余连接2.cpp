/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-24 09:53:54
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-24 10:49:33
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-23 21:45:29
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-24 09:40:24
 */
/*
力扣T685. 冗余连接 II（跟T684的区别是该题的边为有向边）
在本问题中，有根树指满足以下条件的 有向 图。
该树只有一个根节点，所有其他节点都是该根节点的后继。
该树除了根节点之外的每一个节点都有且只有一个父节点，而根节点没有父节点。

输入一个有向图，该图由一个有着 n 个节点（节点值不重复，从 1 到 n）的树及一条附加的有向边构成。
附加的边包含在 1 到 n 中的两个不同顶点间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组 edges 。 每个元素是一对 [ui, vi]，用以表示 有向 图中连接顶点 ui 和顶点 vi 的边，
其中 ui 是 vi 的一个父节点。
返回一条能删除的边，使得剩下的图是有 n 个节点的有根树。若有多个答案，返回最后出现在给定二维数组的答案。

示例 1：
    输入：edges = [[1,2],[1,3],[2,3]]
    输出：[2,3]
示例 2：
    输入：edges = [[1,2],[2,3],[3,4],[4,1],[1,5]]
    输出：[4,1]
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
具体分析见：
https://programmercarl.com/0685.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5II.html#%E6%80%9D%E8%B7%AF
*/

class Solution {
public:
    static const int N = 1010;
    int father[N];
    int n;      // 边的数量

    // 并查集初始化
    void init() {
        for (int i = 1; i <= n; i++) father[i] = i;
    }
    // 并查集寻根过程
    int find(int u) {
        return u == father[u]? u : father[u] = find(father[u]);
    }
    // 将v->u这条有向边加入并查集
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
    // 判断u和v是否找到同一个根
    bool same(int u, int v) {
        u = find(u);
        v = find(v);
        return u == v;
    }
    // 在有向图里找到删除的那条边，使其变成树
    vector<int> getRemoveEdge(const vector<vector<int>>& edges) {
        // 初始化并查集
        init(); 
        // 遍历所有的边
        for (int i = 0; i < n; i++) {
            // 构成有向环了，就是要删除的边
            if (same(edges[i][0], edges[i][1])) return edges[i];
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }

    // 删一条边之后判断是不是树
    bool isTreeAfterRemoveEdge(const vector<vector<int>>& edges, int deleteEdge) {
        init(); // 初始化并查集
        for (int i = 0; i < n; i++) {
            if (i == deleteEdge) continue;
            // 构成有向环了，一定不是树
            if (same(edges[i][0], edges[i][1])) return false;
            join(edges[i][0], edges[i][1]);
        }
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        // 记录节点入度
        int inDegree[N] = {0};
        n = edges.size();
        for (int i = 0; i < n; i++) inDegree[edges[i][1]]++;

        // 记录入度为2的边
        vector<int> vec;
        for (int i = n - 1; i >= 0; i--) {
            if (inDegree[edges[i][1]] == 2) vec.push_back(i);
        }
        // 情况1和情况2：如果只有一个入度为2的节点，那么一定是指向这个节点的边删除一条，看哪个可以构成树
        if (vec.size() > 0)  {
            if (isTreeAfterRemoveEdge(edges, vec[0])) return edges[vec[0]];
            else return edges[vec[1]];
        }
        // 情况三：没有入度为2的节点，图中一定有环，那么找出构成环的边返回即可
        return getRemoveEdge(edges);
    }
};

