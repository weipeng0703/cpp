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
// 1.深度优先搜索
class Solution {
private:
    bool flag = true;
    vector<int> visited;     // 存储节点状态：0代表未访问，1代表访问中，2代表访问过
    vector<vector<int>> edges;
public:
    void dfs(int u)
    {
        // 该先修课程正在被访问
        visited[u] = 1;
        // 遍历该先修课程的后修课程
        for (int v : edges[u])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (flag == false)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                flag = false;
                return;
            }
        }
        // 深度遍历完u将其状态设为已访问
        visited[u] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 将private中的两个参数数组调整大小
        edges.resize(numCourses);
        visited.resize(numCourses);
        // 建立字典记录课程之间的先修关系.example[1]为example[0]的先修课程
        for (const auto& example : prerequisites)
        {
            edges[example[1]].push_back(example[0]);
        }
        for (int i = 0; i < numCourses && flag == true; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }
        return flag;
    }
};