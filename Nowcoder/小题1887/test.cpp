#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
using namespace std; 
// 1.使用辅助数组
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        string ans="";
        // 直接对字符串进行遍历
        for(auto x:s){
            // 对空白字符进行替换
            if(x==' '){
                ans+="%20";
            // 否则不进行处理
            }
            else
            {
                ans+=x;
            }
        }
        return ans;
    }
};
// 我们需要对长度为n的字符串遍历一次，时间复杂度为O(n),
// 需要存储长度为n的字符串，空间复杂度为O(n)

// 2.直接使用.replace()方法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        for (int i=0; i<s.size(); i++){
            if (s[i] == ' '){
                // 注意replace()后面双引号表示字符串""
                s.replace(i,1,"%20");//从i位置开始的1个字符替换为%20
            }
        }
        return s;
    }
};