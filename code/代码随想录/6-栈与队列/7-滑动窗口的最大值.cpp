/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-11 10:54:10
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-11 15:37:10
 */
/*
力扣239. 滑动窗口最大值
给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。
你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
返回 滑动窗口中的最大值 。

示例 1：
    输入：nums = [1,3,-1,-3,5,3,6,7], k = 3
    输出：[3,3,5,5,6,7]
    解释：
    滑动窗口的位置                最大值
    ---------------               -----
    [1  3  -1] -3  5  3  6  7      3
    1 [3  -1  -3] 5  3  6  7       3
    1  3 [-1  -3  5] 3  6  7       5
    1  3  -1 [-3  5  3] 6  7       5
    1  3  -1  -3 [5  3  6] 7       6
    1  3  -1  -3  5 [3  6  7]      7
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

// 1. 暴力会超时
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        if (k == 1) return nums;

        for (int i = 0; i + k - 1 < nums.size(); i++) {
            int temp = INT_MIN;
            for (int j = i; j < i + k; j++) temp = max(temp, nums[j]);
            ans.push_back(temp);
        }
        return ans;
    }
};
// 2.优先队列（堆排序）
// priority_queue:在优先队列中，优先级高的元素先出队列，并非按照先进先出的要求，类似一个堆(heap)。
// 其模板声明带有三个参数，priority_queue<Type, Container, Functional>, 
// 其中Type为数据类型，Container为保存数据的容器，Functional为元素比较方式。
// Container必须是用数组实现的容器，比如 vector, deque. STL里面默认用的是vector. 
// 比较方式默认用operator< , 所以如果把后面两个参数缺省的话，优先队列就是大顶堆，队头元素最大。
// pair类型放入优先队列中总是先比较first的大小,相同在比较second的大小

// priority_queue第三个参数用于比较左右两个值中哪个优先级更低，因此和直觉相反，大顶堆用less，小顶堆用greater
// priority_queue()，默认按照从小到大排列。所以top()返回的是最大值而不是最小值！
// 使用greater<>后，数据从大到小排列，top()返回的就是最小值而不是最大值！
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        if (k == 1) return nums;
        
        // 优先队列第一位储存数组元素nums[i]，第二位储存该数在数组中的索引i
        priority_queue<pair<int, int>> q;
        // 将第一个滑动数组中的值存进去
        for (int i = 0; i < k; i++) q.emplace(nums[i], i);
        // 将第一个滑动数组中的最大值存入结果数组
        ans.push_back(q.top().first);
        for (int i = k; i < nums.size(); i++) {
            // 滑动窗口右移一位，加入一个新元素
            q.emplace(nums[i], i);
            // 新增加了一个数，若之前的最大值位置不在滑动窗口中应将其删除
            while (q.top().second <= i - k) q.pop();
            // 将此时滑动窗口中的最大值放入结果数组
            ans.push_back(q.top().first);
        }
        return ans;
    }
};
// 时间复杂度：O(nlogn)
// 空间复杂度：O(n)，单调队列