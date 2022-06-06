/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-06-06 10:48:49
 * @LastEditors: weipeng
 * @LastEditTime: 2022-06-06 10:49:02
 */
/*
力扣841. 钥匙和房间
有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。
你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。
当你进入一个房间，你可能会在里面找到一套不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。
你可以拿上所有钥匙去解锁其他房间。
给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。
如果能进入 所有 房间返回 true，否则返回 false。

示例 1:
    输入：rooms = [[1],[2],[3],[]]
    输出：true
    解释：
    我们从 0 号房间开始，拿到钥匙 1。
    之后我们去 1 号房间，拿到钥匙 2。
    然后我们去 2 号房间，拿到钥匙 3。
    最后我们去了 3 号房间。
    由于我们能够进入每个房间，我们返回 true。
示例 2：
    输入：rooms = [[1,3],[3,0,1],[2],[0]]
    输出：false
    解释：我们不能进入 2 号房间。
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<queue>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1-广搜
class Solution {
public:
    bool bfs(const vector<vector<int>>& rooms) {
        // 用于标记房间是否被访问过
        vector<int> visited(rooms.size(), 0);
        // 从第一个房间开始
        visited[0] = 1;
        // 广搜用队列
        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int key = q.front();
            q.pop();
            // 从room取出key可以访问到的房间
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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        return bfs(rooms);
    }
};

// 2-深搜
class Solution {
public:
    void dfs(int num, vector<vector<int>>& rooms, vector<int>& visited) {
        if (visited[num] == 1) return;
        visited[num] = 1;
        vector<int> temp = rooms[num];
        for (int ele : temp) dfs(ele, room, visited);
        return;
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(0, rooms, visited);
        for (int ele : visited) {
            if (ele == 0) return false;
        }
        return true;
    }
};