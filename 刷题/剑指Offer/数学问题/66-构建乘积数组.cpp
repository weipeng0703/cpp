/*
给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B[i] 的值是数组 A 中除了下标 i 以外的元素的积, 
即 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

示例 1：
    输入: [1,2,3,4,5]
    输出: [120,60,40,30,24]
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

// 使用矩阵的上下三角部分去做
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int len = a.size();
        if (len == 0)
        {
            return {};
        }
        vector<int> b(len, 1);
        b[0] = 1;
        int temp = 1;
        // 先求出矩阵的下三角部分
        for (int i = 1; i < len; i++)
        {
            b[i] = b[i - 1] * a[i - 1];
        }
        // 求矩阵上三角部分的元素乘积，
        // 再将其与之前求得的下三角部分相乘，即可得到答案
        for (int i = len - 2; i >= 0; i--)
        {
            temp *= a[i + 1];
            b[i] *= temp;
        }
        return b;
    }
};