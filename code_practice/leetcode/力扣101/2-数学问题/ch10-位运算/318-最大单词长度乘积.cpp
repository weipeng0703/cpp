/*
给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，并且这两个单词不含有公共字母。
如果不存在这样的两个单词，返回 0 。

示例 1：

    输入：words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    输出：16 
    解释：这两个单词为 "abcw", "xtfn"。
示例 2：

    输入：words = ["a","ab","abc","d","cd","bcd","abcd"]
    输出：4 
    解释：这两个单词为 "ab", "cd"。
示例 3：

    输入：words = ["a","aa","aaa","aaaa"]
    输出：0 
    解释：不存在这样的两个单词。
*/
#include<vector> 
#include<cmath> 
#include <random>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int size = words.size();
        // 建立一个跟words大小相同的vector，其中每个元素都是26位0
        vector<bitset<26>> bts(size, 0);
        vector<int> length(size, 0);

        for (int i = 0; i < size; i++)
        {
            length[i] = words[i].size();

            for (char ch : words[i])
            {
                // 做set运算，对于单词中出现的字母，在26位的对应位置设为1
                bts[i].set(ch - 'a');
            }
            
        }
        int res = 0;
        for (int i = 0; i < size; i++)
        {
            for (size_t j = 1; j < size; i++)
            {
                if (bts[i] & bts[j] == 0)
                {
                    res = max(res, len[i] * len[j]);
                }
                
            }
            
        }
        return res; 
        
    }
};