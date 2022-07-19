/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-19 10:39:39
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-19 10:39:52
 */
/*
力扣-剑指 Offer II 117. 相似的字符串
如果交换字符串 X 中的两个不同位置的字母，使得它和字符串 Y 相等，那么称 X 和 Y 两个字符串相似。
如果这两个字符串本身是相等的，那它们也是相似的。
例如，"tars" 和 "rats" 是相似的 (交换 0 与 2 的位置)； "rats" 和 "arts" 也是相似的，但是 "star" 不与 "tars"，"rats"，或 "arts" 相似。

总之，它们通过相似性形成了两个关联组：{"tars", "rats", "arts"} 和 {"star"}。
注意，"tars" 和 "arts" 是在同一组中，即使它们并不相似。
形式上，对每个组而言，要确定一个单词在组中，只需要这个词和该组中至少一个单词相似。

给定一个字符串列表 strs。列表中的每个字符串都是 strs 中其它所有字符串的一个 字母异位词 。
请问 strs 中有多少个相似字符串组？
字母异位词（anagram），一种把某个字符串的字母的位置（顺序）加以改换所形成的新词。

示例 1：
    输入：strs = ["tars","rats","arts","star"]
    输出：2
示例 2：
    输入：strs = ["omv","ovm"]
    输出：1
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

// 1-BFS
// 通过BFS计算相似字符串的集合个数
class Solution {
public:
    // 判断两个字符是否相似（即判断两个字符对应位置不同个数是否<=2,是的话可以经过一次交换得到）
    bool isSimilar(string& s1, string& s2) {
        // if (s1 && !s2) return false;
        // if (!s1 && s2) return false;
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff <= 2;
    }
    void bfs(vector<string>& strs, vector<bool>& isVisited, int cur) {
        queue<int> q;
        q.push(cur);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            isVisited[i] = true;
            for (int j = 0; j < strs.size(); j++) {
                if (isSimilar(strs[i], strs[j]) && !isVisited[j]) q.push(j);
            }
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        if (strs.size() == 0) return 0;
        vector<bool> isVisited(strs.size(), false);
        int ans = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (!isVisited[i]) {
                bfs(strs, isVisited, i);
                ans++;
            }
        }
        return ans;
    }
};
// 2-DFS
// 通过DFS计算相似字符串的集合个数
class Solution {
public:
    // 判断两个字符是否相似（即判断两个字符对应位置不同个数是否<=2,是的话可以经过一次交换得到）
    bool isSimilar(string& s1, string& s2) {
        // if (s1 && !s2) return false;
        // if (!s1 && s2) return false;
        if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        return diff <= 2;
    }
    void dfs(vector<string>& strs, vector<bool>& isVisited, int cur) {
        isVisited[cur] = true;
        for (int j = 0; j < strs.size(); j++) {
            if (isSimilar(strs[i], strs[j]) && !isVisited[j]) dfs(strs, isVisited, j);
        }
    }
    int numSimilarGroups(vector<string>& strs) {
        if (strs.size() == 0) return 0;
        vector<bool> isVisited(strs.size(), false);
        int ans = 0;
        for (int i = 0; i < strs.size(); i++) {
            if (!isVisited[i]) {
                dfs(strs, isVisited, i);
                ans++;
            }
        }
        return ans;
    }
};