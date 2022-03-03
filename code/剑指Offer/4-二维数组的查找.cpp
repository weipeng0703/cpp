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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        // 注意，如果数组为空，没法给m或n赋值，所以下面的判断无法进行
        // 应该直接在最开始堆数组是否为直接进行判断
        // if(m == 0 || n == 0)
        // {
        //     return false;
        // }
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == target)
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
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        int m = 0, n = matrix[0].size() - 1;
        while(m < matrix.size() && n >= 0)
        {
            int temp = matrix[m][n];
            if(temp > target)
            {
                n--;
            }
            else if(temp < target)
            {
                m++;
            }
            else{
                return true;
            }
        }
        return false;
    }
};