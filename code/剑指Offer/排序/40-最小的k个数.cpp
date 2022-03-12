/*
输入整数数组 arr ，找出其中最小的 k 个数。
例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
示例 1:
    输入：arr = [3,2,1], k = 2
    输出：[1,2] 或者 [2,1]
示例二:
    输入：arr = [0,1,2,1], k = 1
    输出：[0]
*/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<queue>
#include<set>
#include<vector>
#include<stdio.h>
#include<iomanip>
#include<algorithm>
#include<unordered_map>
using namespace std; 

class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> res;
        if (arr.size() == 0)
        {
            return res;
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < k; i++)
        {
            res.push_back(arr[i]);
        }
        return res;
    }
};