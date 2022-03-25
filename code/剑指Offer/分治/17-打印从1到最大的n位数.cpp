/*
输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。
示例 1:
    输入: n = 1
    输出: [1,2,3,4,5,6,7,8,9]
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
using namespace std; 

// 暴力
class Solution {
public:
    vector<int> printNumbers(int n) {
        if (n == 1)
        {
            return vector<int>{1,2,3,4,5,6,7,8,9};
        }
        vector<int> ans;
        n--;
        int num = 9;
        while (n != 0)
        {
            num = num * 10 + 9;
            --n;
        }
        for (int i = 1; i <= num; i++)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
// 2.dfs+回溯的大数解法
class Solution {
public:
    vector<string> res;
    string curr;
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    void dfs(int x, int n){
        if (x == n)
        {
            res.push_back(curr);
            return;
        }
        // 确定从左到右的开始位置start
        int start = x == 0? 1 : 0;
        for (int i = start; i < 10; i++)
        {
            curr.push_back(num[i]);
            dfs(i + 1, n);
            curr.pop_back();
        }
    }
    vector<int> printNumbers(int n) {
        for (int i = 1; i < n; i++)
        {
            dfs(0, i);
        }
        vector<int> resInt;
        for (auto ele : res)
        {
            resInt.push_back(stoi(ele));
        }
        return resInt;
    }
};