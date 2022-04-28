/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-27 19:07:21
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-28 11:34:20
 */
/*
力扣332. 重新安排行程
给你一份航线列表 tickets ，其中 tickets[i] = [fromi, toi] 表示飞机出发和降落的机场地点。请你对该行程进行重新规划排序。
所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。如果存在多种有效的行程，请你按字典排序返回最小的行程组合。
例如，行程 ["JFK", "LGA"] 与 ["JFK", "LGB"] 相比就更小，排序更靠前。
假定所有机票至少存在一种合理的行程。且所有的机票 必须都用一次 且 只能用一次。
示例 1：
https://leetcode-cn.com/problems/reconstruct-itinerary/
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
#include<priority_queue>
using namespace std; 


class Solution {
public:
    vector<string> ans;
    // 存储<始发机场, <到达机场, 始发机场到该到达机场的航线数>>
    unordered_map<string, map<string, int>> targets;

    bool backtrack(vector<string>& ans, int ticketNum) {
        // 票数加1即为途径的机场个数
        if (ans.size() == ticketNum + 1) return true;
        // 遍历所有将要到达的目的机场
        for (pair<const string, int>& target : targets[ans[ans.size() - 1]]) {
            // 如果到目的机场的航线数>0，说明仍有航线
            if (target.second > 0) {
                ans.push_back(target.first);
                target.second--;
                if (backtrack(ans, ticketNum)) return true;
                ans.pop_back();
                target.second++;
            }
        }
            return false;
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        if (tickets.size() == 0) return ans;
        ans.push_back("JFK");
        // 记录映射关系 key->key->value++
        for (const vector<string>& vec : tickets) targets[vec[0]][vec[1]]++;
        backtrack(ans, tickets.size());
        return ans;
    }
};