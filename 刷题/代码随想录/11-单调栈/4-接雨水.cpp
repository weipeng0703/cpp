/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-24 10:02:15
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-25 16:20:19
 */

/*
力扣42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1:
    输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
    输出：6
    解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：
    输入：height = [4,2,0,3,2,5]
    输出：9
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

// 1. 双指针(会超时)
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            if (i == 0 || i == height.size() - 1) continue;

            int lHeight = height[i];
            int rHeight = height[i];
            for (int l = i - 1; l >= 0; l--) lHeight = max(lHeight, height[l]);
            for (int r = i + 1; r < height.size(); r++) rHeight = max(rHeight, height[r]);

            int h = min(lHeight, rHeight) - height[i];
            if (h > 0) ans += h;
        }
        return ans;
    }
};

// 2. dp
// (相较双指针，使用dp数组记录了当前元素左右两遍最高值，不需要重复遍历数组求左右两侧最值)
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        // 记录每个柱子左边的最大高度
        maxLeft[0] = height[0];
        for (int i = 1; i < height.size(); i++) maxLeft[i] = max(maxLeft[i - 1], height[i]);
        // 记录每个柱子右边的最大高度
        maxRight[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; i--) maxRight[i] = max(maxRight[i + 1], height[i]);
        // 求和
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            int h = min(maxLeft[i], maxRight[i]) - height[i];
            if (h > 0) ans += h;
        }
        return ans;
    }
};

// 3.单调栈
// 3.单调栈
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<int> st; // 单调栈从栈头到栈尾递增
        st.push(0);
        for (int i = 1; i < height.size(); i++) {
            if (height[i] < height[st.top()]) {
                st.push(i);
            } else if (height[i] == height[st.top()]) {
                st.pop();
                st.push(i);
            } else {
                while (!st.empty() && height[i] > height[st.top()]) {
                    int mid = st.top();     // 凹槽底
                    st.pop();               // 此时栈头为左边最高值
                    if (!st.empty()) {
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};