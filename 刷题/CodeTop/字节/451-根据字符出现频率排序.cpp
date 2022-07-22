/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-22 22:06:03
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-22 22:37:06
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

/*
力扣T-451. 根据字符出现频率排序
给定一个字符串 s ，根据字符出现的 频率 对其进行 降序排序 。一个字符出现的 频率 是它出现在字符串中的次数。
返回 已排序的字符串 。如果有多个答案，返回其中任何一个。

示例 1：
    输入: s = "tree"
    输出: "eert"
    解释: 'e'出现两次，'r'和't'都只出现一次。
    因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
示例 2:
    输入: s = "cccaaa"
    输出: "cccaaa"
    解释: 'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
    注意"cacaca"是不正确的，因为相同的字母必须放在一起。
示例 3:
    输入: s = "Aabb"
    输出: "bbAa"
    解释: 此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
    注意'A'和'a'被认为是两种不同的字符。
*/

// 1-哈希表+sort()
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> umap;
        for (char ch : s) umap[ch]++;
        // lambda表达式[&]表示捕获所有变量
        sort(s.begin(), s.end(), [s](const char& a, const char& b) {
            return mp[a] == mp[b]? a > b : mp[a] >= mp[b];
        })
        return s;
    }
};
// 2-哈希表加桶排序
class Solution {
public:
    string frequencySort(string s) {
        // 哈希表统计每个字符出现的次数及出现的最大次数
        unordered_map<char, int> umap;
        int maxFreq = 0;
        for (auto& ch : s) {
            umap[ch]++;
            maxFreq = max(maxFreq, umap[ch]);
        }
        // 建桶，将出现次数相同的字幕装在同一个桶中
        vector<string> buckets(maxFreq + 1);
        for (auto& kv : umap) {
            buckets[kv.second].push_back(kv.first);
        }
        // 从桶中将字母保存到结果
        string ans;
        // 1-对每一个桶操作(本题是从大到小输出)
        for (int i = maxFreq; i >= 0; i--) {
            // 2-因为每一个桶中的元素buckets[i]就是一个字符串
            for (auto& ch : buckets[i]) {
                // 3-将桶中字符串中的字母存入ans
                for (int j = 0; j < i; j++) {
                    ans.push_back(ch);
                }
            }
        }
        return ans;
    }
};