/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-23 15:22:58
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-24 09:06:24
 */

/*
力扣739. 每日温度
给定一个整数数组 temperatures ，表示每天的温度，
返回一个数组 answer ，其中 answer[i] 是指在第 i 天之后，才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替

示例 1:
    输入: temperatures = [73,74,75,71,69,72,76,73]
    输出: [1,1,4,2,1,1,0,0]
示例 2:
    输入: temperatures = [30,40,50,60]
    输出: [1,1,1,0]
示例 3:
    输入: temperatures = [30,60,90]
    输出: [1,1,0]
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

// 思路：详细图解见下
// https://programmercarl.com/0739.%E6%AF%8F%E6%97%A5%E6%B8%A9%E5%BA%A6.html#%E6%80%9D%E8%B7%AF

// 1. 单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size, 0);
        // 栈里只保存数组的下标，递增栈（从栈头到栈底的下标所代表的数据是递增的）
        stack<int> st;
        st.push(0);
        for (int i = 1; i < size; i++) {
            if (temperatures[i] < temperatures[st.top()]) {
                st.push(i);
            } else if (temperatures[i] == temperatures[st.top()]) {
                st.push(i);
            } else {
                // 此处注意，判断栈非空的条件一定要在前，否则会运行错误
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};

// 2.暴力遍历（会超时）
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if (size == 1) return vector<int> {0};
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (temperatures[j] - temperatures[i] > 0) {
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};