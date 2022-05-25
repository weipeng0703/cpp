/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-25 16:24:23
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-25 19:13:44
 */

/*
力扣84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。

示例 1:
    输入：heights = [2,1,5,6,2,3]
    输出：10
    解释：最大的矩形为图中红色区域，面积为 10
示例 2：
    输入： heights = [2,4]
    输出： 4
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

// 1. 双指针
// 遍历数组，对于每个矩形向左和向右寻找第一个比它小的位置，此时以他为中心的矩形的面积是最大的
// 遍历每一个位置求面积，取最大面积
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int left = i;
            int right = i;
            for (; left >= 0; left--) {
                if (heights[left] < heights[i]) break;
            }
            for (; right < heights.size(); right++) {
                if (heights[right] < heights[i]) break;
            }
            int w = right - left - 1, h = heights[i];
            ans = max(ans, w * h);
        }
        return ans;
    }
};

// 2. dp
// dp数组记录当前位置左面与右面第一个小于该值的位置
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(height.size(), -1);
        vector<int> minRightIndex(height.size(), height.size());

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
            while (temp >= 0 && heights[temp] >= heights[i]) temp = minRightIndex[temp];
            // 如果小于该位置高度，记录该位置
            minRightIndex[i] = temp;
        }
        // 求结果
        int ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            int h = heights[i], w = minRightIndex[i] - minLeftIndex[i];
            ans = max(ans, h * w);
        }
        return ans;
    }
};

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();

        // 记录每个柱子 左边第一个小于该柱子的下标
        minLeftIndex[0] = -1; // 注意这里初始化，防止下面while死循环
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // 这里不是用if，而是不断向左寻找的过程
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        // 记录每个柱子 右边第一个小于该柱子的下标
        minRightIndex[size - 1] = size; // 注意这里初始化，防止下面while死循环
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            // 这里不是用if，而是不断向右寻找的过程
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        // 求和
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};

// 3. 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        // 给height的开头与结尾各添加一个0,保证heights内元素求解的一致性
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        int ans = 0;
        st.push(0);
        // 遍历heights元素,每个元素都做单调栈处理
        for (int i = 1; i < heights.size(); i++) {
            if (heights[i] > heights[st.top()]) {
                st.push(i);
            } else if (heights[i] == heights[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && heights[i] < heights[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    int left = st.top();
                    int right = i;
                    int w = right - left - 1;
                    int h = heights[mid];
                    ans = max(ans, h * w);
                }
                st.push(i);
            }
        }
        return ans;
    }
};
