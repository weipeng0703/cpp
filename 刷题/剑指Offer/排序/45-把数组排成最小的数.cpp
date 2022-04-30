/*
输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
示例 1:
    输入: [10,2]
    输出: "102"
示例二:
    输入: [3,30,34,5,9]
    输出: "3033459"
说明:
    输出结果可能非常大，所以你需要返回一个字符串而不是整数
    拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
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

// 自定义排序具体原理看:
// https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/solution/mian-shi-ti-45-ba-shu-zu-pai-cheng-zui-xiao-de-s-4/
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> temp;
        string ans;
        if(nums.size() == 0){
            return ans;
        }
        for(int i = 0; i < nums.size(); i++){
            temp.push_back(to_string((nums[i])));
        }
        sort(temp.begin(), temp.end(), [](string& a, string& b){return a + b < b + a;});
        for(int i = 0; i < temp.size(); i++){
            ans += temp[i];
        }
        return ans;
    }
};