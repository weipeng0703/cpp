/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-08-01 14:36:55
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-01 20:02:07
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-06 22:26:00
 * @LastEditors: weipeng
 * @LastEditTime: 2022-08-01 14:35:43
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
力扣T-85. 最大矩形
给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

示例 1：
    输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    输出：6
    解释：最大矩形如上图所示。
示例 2：
    输入：matrix = []
    输出：
*/ 

// 1-使用T-84中的思路
// 依次求解矩阵中每一行能构成的最大矩形的面积

// 1-T-84中dp的思路
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return 0;
        int ans = 0;
        vector<int> temp(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') temp[j] = 0;
                /*
                    例如如果matrix为下面这样
                    [1, 0, 1, 1]
                    [1, 0, 1, 1]
                    那么第一行temp为[1, 0, 1, 1]，此时最大矩形面积为2
                    那么第二行temp为[2, 0, 2, 2]，此时最大矩形面积为4
                */
                else temp[j] += 1;
            }
            ans = max(ans, largestRectangleArea(temp));
        }
        return ans;
    }
};

// 2-T-84中单调栈的思路
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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return 0;
        int ans = 0;
        vector<int> temp(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '0') temp[j] = 0;
                /*
                    例如如果matrix为下面这样
                    [1, 0, 1, 1]
                    [1, 0, 1, 1]
                    那么第一行temp为[1, 0, 1, 1]，此时最大矩形面积为2
                    那么第二行temp为[2, 0, 2, 2]，此时最大矩形面积为4
                */
                else temp[j] += 1;
            }
            ans = max(ans, largestRectangleArea(temp));
        }
        return ans;
    }
};




int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int N = heights.size();
        stack<int> stk;
        int maxArea = 0;
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && heights[i] < heights[stk.top()]) {
                auto height = heights[stk.top()];
                stk.pop();
                int width = stk.empty() ? i : i - stk.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            
            stk.push(i);
        }  

        return maxArea;     
    }

// 作者：jyj407
// 链接：https://leetcode.cn/problems/maximal-rectangle/solution/by-jyj407-1uhd/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。