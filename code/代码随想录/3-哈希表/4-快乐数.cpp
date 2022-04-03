/*
力扣202. 快乐数
编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
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

class Solution {
public:
    // 求数位平方和
    int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        if (n == 0) return false;

        unordered_set<int> st;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) return true;
            // 如果这个sum曾经出现过，说明已经陷入循环了，立即return false;
            if (st.find(sum) != st.end()) {
                return false;
            } else {
                st.insert(sum);
            }
            // 继续求数位的平方和
            n = sum;
        }
        
    }
};