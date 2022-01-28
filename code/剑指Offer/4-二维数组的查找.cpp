/*
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。
给定 target = 3，返回 false。 
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
using namespace std; 
// 1.直接遍历查找
// 会造成数组越界，堆栈溢出（比如，递归调用层数太多）等情况引起
class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int n = array.size();       // 行数
        int m = array[0].size();    // 列数

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; i < m; j++)
            {
                if (array[i][j] == target)
                {
                    return true;
                }
                
            }
            
        }
        return false;
    }
};
// 2.巧妙方法，选取数组左上角的数字
// 若该数字等于目标数字，返回true
// 若该数字大于目标数字，删去该数字所在的列
// 若该数字小于目标数字，删除该数字所在的行
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int n = array.size();       // 行数
        int m = array[0].size();    // 列数

        if (n == 0 && m == 0)
        {
            return false;
        }
        
        int i = 0;
        int j = m - 1; 
        while (i < n && j >= 0)
        {
            if (array[i][j] == target)
            {
                return true;
            }
            else if (array[i][j] > target)
            {
                j--;
            }
            else if (array[i][j] < target)
            {
                i++;
            }
            
        }
        return false;
    }
};