/*
给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]

示例 2:

输入: nums = [1], k = 1
输出: [1]

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一：哈希表+堆的思想
class Solution {
public:
    bool compare(pair<int, int>& m, pair<int, int>& n)
    {
        return m.second > n.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> occur;
        for (auto& v : nums)
        {
            occur[v]++;
        }

        // pair第一个元素代表数组的值，第二个元素代表该值出现的次数
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> q(compare);

        for (auto& [num, count] : occur)
        {
            if (q.size() == k)
            {
                if (q.top.second < count)
                {
                    q.pop();
                    q.emplace(num, count);
                }
                else
                {
                    q.emplace(num, count);
                }
                
            }
        }
        vector<int> res;
        while (!q.empty())
        {
            ret.emplace_back(q.top().first);
            q.pop();
        }
            
        return res;
    }
};

// 方法二，桶排序
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int maxCount = 0;

        unordered_map<int, int> hash_map;
        for (auto num : nums) {
            hash_map[num]++;
            // 统计每个number出现的次数，保留最大次数 
            maxCount = max(maxCount, hash_map[num]);
        }

        // 以最大次数建桶
        vector<vector<int>> buckets(maxCount + 1);
        // 将出现的 number 按照出现的次数，填入对应的桶中
        for (auto kv : hash_map) {
            int number = kv.first;
            int count = kv.second;
            buckets[count].push_back(number);
        }

        // 按倒序，找到出现次数前 k 高的元素
        vector<int> res;
        for (int i = maxCount; i >= 0; i--) {
            // k 为 0 表示，已经找到出现频率前k高的元素
            if (k == 0) break;
            // 如果当前频率的桶为空，则跳过
            if (!buckets[i].size()) continue;
            // 不为空则把桶内元素加入 res 数组, 使要找的频率 k--
            for (int j = 0; j < buckets[i].size(); j++) {
                int number = buckets[i][j];
                res.push_back(number);
                k--;
            }
        }
        return res;
    }
};