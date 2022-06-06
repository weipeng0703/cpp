/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-06 10:50:07
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-06 16:11:12
 */
/*
力扣T207-课程表
你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，
其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习。如果可以，返回 true ；否则，返回 false 。

示例 1：
    输入：numCourses = 2, prerequisites = [[1,0]]
    输出：true
    解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
示例 2：
    输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
    输出：false
    解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；
    并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.深搜
class Solution {
public:
    bool flag = true;
    // 存储节点状态：0代表未访问，1代表访问中，2代表访问过
    vector<int> visited;
    // edges用于记录某一门课是哪些课的先修课程(构造拓扑排序的先后序关系)
    vector<vector<int>> edges;

    void dfs(int u) {
        // 该先修课程正在被访问
        visited[u] = 1;
        // 遍历该先修课程的后修课程
        vector<int> temp = edges[u];
        for (int v : temp) {
            if (visited[v] == 0) {
                dfs(v);
                if (flag == false) return;
            } else if (visited[v] == 1) {
                flag = false;
                return;
            }
        }
        // 深度遍历完u将其状态设为已访问
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 调整两个参数数组的大小
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 建立字典记录课程之间的先修关系.example[1]为example[0]的先修课程
        for (const auto& example : prerequisites) edges[example[1]].push_back(example[0]);
        for (int i = 0; i < numCourses && flag == true; i++) {
            if (visited[i] == 0) dfs(i);
        }
        return flag;
    }
};


// 2-广搜
class Solution {
public:
    bool flag = true;
    // edges用于记录某一门课是哪些课的先修课程(构造拓扑排序的先后序关系)
    vector<vector<int>> edges;
    // 记录某一门课有几门先修课程
    vector<int> indeg;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 调整两个参数数组的大小
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 建立字典记录课程之间的先修关系.example[1]为example[0]的先修课程
        for (const auto& example : prerequisites) {
            edges[example[1]].push_back(example[0]);
            indeg[example[0]]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        // 记录遍历完的课程有多少
        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int temp = q.front();
            q.pop();
            for (int ele : edges[temp]) {
                --indeg[ele];
                if (indeg[ele] == 0) q.push(ele);
            }
        }
        return visited == numCourses;
    }
};





// 深搜另一种写法（没有ac）
// 1.深搜
class Solution {
public:
    void dfs(int u, vector<vector<int>>& edges, vector<int>& visited) {
        // 如果课程u遍历过
        if (visited[u] == 1) return;
        // 如果课程u没遍历过
        visited[u] = 1;
        vector<int> temp = edges[u];
        for (int v : temp) dfs(v, edges, visited);
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 存储节点状态：0代表未访问，1代表访问过
        vector<int> visited(numCourses, 0);
        // 建立字典记录课程之间的先修关系.example[1]为example[0]的先修课程

        vector<vector<int>> edges(1e5, vector<int>());
        for (const auto& example : prerequisites) edges[example[1]].push_back(example[0]);

        dfs(0, edges, visited);
        for (int i : visited) {
            if (i == 0) return false;
        }
        return true;
    }
};


// 广搜的另一种写法(没有ac)
class Solution {
public:
    bool flag = true;
    // edges用于记录某一门课是哪些课的先修课程(构造拓扑排序的先后序关系)
    vector<vector<int>> edges;
    vector<int> visited;
    bool bfs(const vector<vector<int>>& rooms) {
        // 用于标记某课程是否被访问过
        vector<int> visited(rooms.size(), 0);
        // 从第一个课程开始
        visited[0] = 1;
        // 广搜用队列
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int key = q.front();
            q.pop();

            vector<int> temp = rooms[key];
            for (int key : temp) {
                if (visited[key] == 0) {
                    q.push(key);
                    visited[key] = 1;
                }
            }
        }
        for (int ele : visited) {
            if (ele == 0) return false;
        }
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 调整两个参数数组的大小
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 建立字典记录课程之间的先修关系.example[1]为example[0]的先修课程
        for (const auto& example : prerequisites) {
            edges[example[1]].push_back(example[0]);
        }
        return bfs(edges);
    }
};