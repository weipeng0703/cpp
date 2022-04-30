/*
力扣347. 前 K 个高频元素
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:
    输入: nums = [1,1,1,2,2,3], k = 2
    输出: [1,2]
示例 2:
    输入: nums = [1], k = 1
    输出: [1]
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

// 1.哈希表+优先队列（堆排序）
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0) return ans;
        // 将[数，该数出现的次数]存入哈希表
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) umap[nums[i]]++;
        // 将哈希表中的数据存入大顶堆
        priority_queue<pair<int, int>> que;
        for (auto& [num, count] : umap) {
            que.emplace(count, num);
        }
        // 做K次pop求出现次数前K高的数
        while (k--){
            ans.push_back(que.top().second);
            que.pop();
        }
        return ans;
    }
};

// 2.哈希表+优先队列（堆排序）+优化(使用小顶堆)
class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n) {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occurrences;
        for (auto& v : nums) {
            occurrences[v]++;
        }

        // pair 的第一个元素代表数组的值，第二个元素代表了该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        for (auto& [num, count] : occurrences) {
            if (q.size() == k) {
                // 对于小顶堆，如果当前顶堆的大小跟k相等，且刚进来的数字出现的次数大于顶堆数字出现的次数
                // 可以先将顶堆数字弹出（他肯定不在前k个高频数字中）
                if (q.top().second < count) {
                    q.pop();
                    q.emplace(num, count);
                }
            } else {
                q.emplace(num, count);
            }
        }
        vector<int> ret;
        while (!q.empty()) {
            ret.emplace_back(q.top().first);
            q.pop();
        }
        return ret;
    }
};
