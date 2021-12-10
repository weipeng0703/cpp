/*
给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:
    输入:
    "tree"

    输出:
    "eert"

    解释:
    'e'出现两次，'r'和't'都只出现一次。
    因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。

示例 2:

    输入:
    "cccaaa"

    输出:
    "cccaaa"

    解释:
    'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
    注意"cacaca"是不正确的，因为相同的字母必须放在一起。

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

// 方法一:哈希表加sort()
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for(auto ch:s) 
            mp[ch]++;
        sort(s.begin(),s.end(),[&](const char &a, const char &b){
            // 如果出现次数相同，则按照字母序排列
            // 出现次数不相等，则出现次数多的置前
            return mp[a]==mp[b] ? a>b : mp[a]>mp[b];
        });
        return s;
    }
};

// 方法二:桶排序
class Solution {
public:
    string frequencySort(string s) {
        // 建立哈希表记录字母及其出现的次数
        unordered_map<char, int> mp;
        int maxFreq = 0;
        int length = s.size();
        for (auto &ch : s) {
            maxFreq = max(maxFreq, ++mp[ch]);
        }

        // 建桶，将字母装入桶中
        vector<string> buckets(maxFreq + 1);
        for (auto &kv : mp) {
            buckets[kv.second].push_back(kv.first);
        }

        string ret;
        // 对每一个桶进行操作
        for (int i = maxFreq; i > 0; i--) {
            string &bucket = buckets[i];
            for (auto &ch : bucket) {
                // 往res中装入出现次数个字母
                for (int k = 0; k < i; k++) {
                    ret.push_back(ch);
                }
            }
        }
        return ret;
    }
};
