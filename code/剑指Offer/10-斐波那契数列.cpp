/*

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
// 1.递归（效率非常低）
class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 0)
            return 0;
        else if(n == 1)
            return 1;
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
};
// 2.记录中间数据
class Solution {
public:
    int Fibonacci(int n) {
        vector<int> ans = {0,1};
        if (n < 2)
        {
            return ans[n];
        }
        int Fib_1 = 1;
        int Fib_0 = 0;
        int Fib_N = 0;
        for (int i = 2; i <= n; i++)
        {
            Fib_N = Fib_0 + Fib_1;
            Fib_1 = Fib_N;
            Fib_0 = Fib_1;
        }
        return Fib_N;
    }
};

