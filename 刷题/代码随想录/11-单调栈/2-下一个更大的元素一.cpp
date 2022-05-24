/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-24 09:07:41
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-24 09:32:49
 */

/*
力扣496. 下一个更大元素 I
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。
给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。
对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，
并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。
返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

示例 1:
    输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
    输出：[-1,3,-1]
示例 2:
    输入：nums1 = [2,4], nums2 = [1,2,3,4].
    输出：[3,-1]
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

// 1. 单调栈
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> st;
        unordered_map<int, int> umap;
        // 记录nums1中元素与下标的位置关系
        for (int i = 0; i < nums1.size(); i++) umap[nums1[i]] = i;
        st.push(0);
        for (int i = 1; i < nums2.size(); i++) {    // 因为nums1是nums2的子集，遍历nums2
            if (nums2[i] <= nums2[st.top()]) st.push(i);
            else {
                while (!st.empty() && nums2[i] > nums2[st.top()]) {
                    if (umap.count(nums2[st.top()]) > 0) {  // 看nums1中是否存在这个数
                        int index = umap[nums2[st.top()]];  // 如果nums1中存在这个数，求该数的位置
                        ans[index] = nums2[i];
                    }
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};