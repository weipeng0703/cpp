/*
请实现一个函数，将一个字符串s中的每个空格替换成“%20”（即空格的ASCII码转换得来的16进制数字）。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
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
// 1.直接从前往后遍历进行替换
// 时间复杂度：对于含有n个字符的字符串，对于每个空格，需要移动后面O(n)个字符，所以
// 时间效率是O(n的平方)

// 2.从后往前进行替换
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
        int n = 0;
        int blank_num = 0;
        int temp = 0;
        while (s[temp] != '\0')
        {
            n++;
            if (s[temp] == ' ')
            {
                blank_num++;
            }
            temp++;
        }
        int new_size = n + 2 * blank_num;

        int indexOfOriginal = n + 1;
        int indexOfNew = new_size;
        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
        {
            if (s[indexOfOriginal] == ' ')
            {
                s[indexOfNew--] = '0';
                s[indexOfNew--] = '2';
                s[indexOfNew--] = '%';
            }
            else
            {
                s[indexOfNew--] = s[indexOfOriginal];
            }
            indexOfOriginal--;
        }
        return s;
    }
};
