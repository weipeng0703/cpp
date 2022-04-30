/*
输入一个字符串，打印出该字符串中字符的所有排列。
你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

示例 1:
    输入：s = "abc"
    输出：["abc","acb","bac","bca","cab","cba"]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

// 1.直接调库
class Solution {
public:
    vector<string> permutation(string s) {
        sort(s.begin(), s.end());
        vector<string> ans;
        do
        {
            ans.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return ans;
    }
};
// 2.回溯+剪枝
class Solution {
public:
    vector<string> ans;
    void dfs(string s, int x){
        if (x == s.size() - 1) {
            ans.push_back(s);
        }
        set<int> st;
        for (int i = x; i < s.size(); i++) {
            if (st.find(s[i]) != st.end())  continue;
            st.insert(s[i]);
            swap(s[x], s[i]);
            dfs(s, x + 1);
            // 对于一种交换方式，其下所有子交换过程结束后，要将其还原，继续进行下一种交换过程
            // 例如 abc， 进行完bac的所有交换过程后，还原ab位置为abc， 继续进行其余交换过程比如cab啥的
            swap(s[i], s[x]);
        }
    }
    vector<string> permutation(string s) {
        if (s.length() == 0)
        {
            return ans;
        }
        dfs(s, 0);
        return ans;
    }
};