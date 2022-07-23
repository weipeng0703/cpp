/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-20 15:25:51
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 11:04:18
 */
/*
力扣-56. 合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

示例 1：
    输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
    输出：[[1,6],[8,10],[15,18]]
    解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：
    输入：intervals = [[1,4],[4,5]]
    输出：[[1,5]]
    解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
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

// 1-贪心
// 1-贪心
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) { return a[0] < b[0];}
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), cmp);
        ans.push_back(intervals[0]);
        // 依次比较intervals[i][0]与答案数组末尾的数据ans.back()[1]的大小
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] >= intervals[i][0]) ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
// 2-贪心+lambda表达式
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {return a[0] < b[0];});
        ans.push_back(intervals[0]);
        // 依次比较intervals[i][0]与答案数组末尾的数据ans.back()[1]的大小
        for (int i = 1; i < intervals.size(); i++) {
            if (ans.back()[1] >= intervals[i][0]) ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};