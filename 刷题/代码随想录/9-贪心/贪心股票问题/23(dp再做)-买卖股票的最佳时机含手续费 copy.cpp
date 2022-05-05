/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-05 09:12:13
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-05 09:12:13
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-04 22:23:02
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-04 22:56:12
 */
/*
力扣738. 单调递增的数字
当且仅当每个相邻位数上的数字 x 和 y 满足 x <= y 时，我们称这个整数是单调递增的。
给定一个整数 n ，返回 小于或等于 n 的最大数字，且数字呈 单调递增 。

示例 1:
    输入: n = 10
    输出: 9
示例 2:
    输入: n = 1234
    输出: 1234
示例 3:
    输入: n = 332
    输出: 299
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

// 1. 暴力(超时)
class Solution {
public:
    bool isValid(int n) {
        vector<int> temp;
        while (n) {
            temp.push_back(n % 10);
            n /= 10;
        }
        for (int i = 1; i < temp.size(); i++){
            if (temp[i - 1] < temp[i]) return false;
        }
        return true;
    }
    int monotoneIncreasingDigits(int n) {
        int ans = 0;
        while (n) {
            if (isValid(n)) {
                ans = n;
                break;
            }
            n--;
        }
        return ans;
    }
};

// 2.贪心
// 从低位数向高位数遍历，若高位数 > 低位数，
// 令高位数--，低位数为9
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        // 用于记录从哪一位开始后面的数均变为9
        int flag = str.size();
        for (int i = str.size() - 1; i >= 1; i--) {
            if (str[i] < str[i - 1]) {
                flag = i;
                str[i - 1]--;
            }
        }
        for (int i = flag; i < str.size(); i++) str[i] = '9';
        return stoi(str);
    }
};