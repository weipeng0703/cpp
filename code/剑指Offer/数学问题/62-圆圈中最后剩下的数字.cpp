/*
0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。
求出这个圆圈里剩下的最后一个数字。
例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，则删除的前4个数字依次是2、0、4、1，
因此最后剩下的数字是3。

示例 1：
    输入: n = 5, m = 3
    输出: 3
示例 2:
    输入: n = 10, m = 17
    输出: 2
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
// #include<unordered_map>
using namespace std; 
// 1.递归
class Solution {
public:
    int curr(int n, int m){
        if (n == 1)
        {
            return 0;
        }
        int x = curr(n - 1, m);
        return (m + x) % n;
    }
    int lastRemaining(int n, int m) {
        return curr(n, m);
    }
};
// 时间复杂度：O(n):需求解的函数值有n个
// 空间复杂度：O(n)。函数的递归深度为n，需要的栈空间为n

// 2.使用迭代代替递归
class Solution {
public:
    int lastRemaining(int n, int m) {
        int f = 0;
        for (int i = 2; i != n + 1; ++i) {
            f = (m + f) % i;
        }
        return f;
    }
};
