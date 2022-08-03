/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-08-01 15:15:57
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-01 16:11:42
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
#include<queue>
using namespace std;
/*
力扣T-84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
示例 1：
    输入：heights = [2,1,5,6,2,3]
    输出：10
    解释：最大的矩形为图中红色区域，面积为 10
示例 2：
    输入： heights = [2,4]
    输出： 4
*/ 

// 1-dp
// dp数组记录当前位置左面与右面第一个小于该值的位置
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(heights.size(), -1);
        vector<int> minRightIndex(heights.size(), heights.size());

        // 记录每一个柱子左边第一个小于该柱子高度的位置
        for (int i = 1; i < heights.size(); i++) {
            int temp = i - 1;
            // 对于 大于等于 该位置的高度，不管
            while (temp >= 0 && heights[temp] >= heights[i]) temp = minLeftIndex[temp];
            // 如果小于该位置高度，记录该位置
            minLeftIndex[i] = temp;
        }
        // 记录每一个柱子右边第一个小于该柱子高度的位置
        for (int i = heights.size() - 2; i >= 0; i--) {
            int temp = i + 1;
            // 对于 大于等于 该位置的高度，不管
            while (temp < heights.size() && heights[temp] >= heights[i]) temp = minRightIndex[temp];
            // 如果小于该位置高度，记录该位置
            minRightIndex[i] = temp;
        }
        // 求结果
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i], w = minRightIndex[i] - minLeftIndex[i] - 1;
            ans = max(ans, h * w);
        }
        return ans;
    }
};
// 2-单调栈
// 该题的单调栈方向根42-接雨水正好相反
// 42是从栈头到栈尾递增，该题从栈头到栈尾递减
// 但是两道题为了处理矩形的面积，栈中存放的都是数组的下标
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> st;
        st.push(0);
        int ans = 0;
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) st.push(i);
            else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    int w = i - st.top() - 1, h = heights[mid];
                    ans = max(ans, h * w);
                }
                st.push(i);
            }
        }
        return ans;
    }
};