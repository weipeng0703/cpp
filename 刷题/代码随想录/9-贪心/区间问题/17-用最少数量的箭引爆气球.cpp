/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-03 10:34:49
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-03 15:09:43
 */
/*
力扣452. 用最少数量的箭引爆气球
有一些球形气球贴在一堵用 XY 平面表示的墙面上。
墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。
你不知道气球的确切 y 坐标。
一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。
在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。
可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。
给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

示例 1:
    输入：points = [[10,16],[2,8],[1,6],[7,12]]
    输出：2
    解释：气球可以用2支箭来爆破:
    -在x = 6处射出箭，击破气球[2,8]和[1,6]。
    -在x = 11处发射箭，击破气球[10,16]和[7,12]。
示例 2:
    输入：points = [[1,2],[3,4],[5,6],[7,8]]
    输出：4
    解释：每个气球需要射出一支箭，总共需要4支箭。
示例 3：
    输入：points = [[1,2],[2,3],[3,4],[4,5]]
    输出：2
    解释：气球可以用2支箭来爆破:
    - 在x = 2处发射箭，击破气球[1,2]和[2,3]。
    - 在x = 4处射出箭，击破气球[3,4]和[4,5]。
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

// 1.贪心
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] <= b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size() == 0) return 0;
        sort(points.beign(), points.end(), cmp);
        int ans = 1;
        for (int i = 1; i < points.size(); i++) {
            // 如果某个气球的左边界大于其前一个气球的右边界，一定需要多一只箭才能射爆
            if (points[i][0] > points[i - 1][1]) ans++;
            // 反之只需要一只箭即可将这两个气球射爆，不需要更新箭数，将后者的气球右边界设置为二者的最小右边界
            // 再跟其之后的区间比较
            else points[i][1] = min(points[i - 1][1], points[i][1]);
        }
        return ans;
    }
};