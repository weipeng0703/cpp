/*
求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
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

// 不能用循环，那就用循环的替代写法——递归
class Solution {
public:
    int sumNums(int n) {
        return n == 0? 0 : n + sumNums(n - 1);
    }
};
// 等差数列求和公式（sorry, 用了乘除法），但是等差数列要记住
class Solution {
public:
    int sumNums(int n) {
        return n * (1 + n) / 2;
    }
};

// 用sizeof求上面的等差数列
// 因为等差数列求和公式 == n (1 + n) / 2
// arr数组的大小sizeof(arr) = n (1 + n)， 右移一位代表该数乘2，所以答案即为n (1 + n) / 2
class Solution {
public:
    int sumNums(int n) {
        bool arr[n][n+1];
        return sizeof(arr) >> 1;
    }
};