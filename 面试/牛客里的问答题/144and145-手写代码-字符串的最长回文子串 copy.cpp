// 题目
/*
手写代码：求一个字符串最长回文子串
*/

// 解答

// 1.暴力求解
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
 string longestPalindrome(string s)
 {
     if(s.empty()) return "";
     if(s.size()==1) return s;
     int start=0,maxlength=1;//记录最大回文子串的起始位置以及长度
     for(int i=0;i<s.size();i++)
         for(int j=i+1;j<s.size();j++)//从当前位置的下一个开始算
         {
             int temp1,temp2;
             for(temp1=i,temp2=j;temp1<temp2;temp1++,temp2--)
             {
                 if(s[temp1]!=s[temp2])
                     break;
             }
             if(temp1>=temp2 && j-i+1>maxlength)//这里要注意条件为temp1>=temp2，因为如果是偶数个字符，相邻的两个经上一步会出现大于的情况
             {
                 maxlength = j-i+1;
                 start=i;
             }
         }
    return s.substr(start,maxlength);//利用string中的substr函数来返回相应的子串,第一个参数是起始位置，第二个参数是字符个数
 }