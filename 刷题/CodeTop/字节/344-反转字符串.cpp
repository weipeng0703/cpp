/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-07-23 10:00:37
 * @LastEditors: weipeng
 * @LastEditTime: 2022-07-23 10:12:47
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

/*
力扣T-344. 反转字符串
编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

示例 1：
    输入：s = ["h","e","l","l","o"]
    输出：["o","l","l","e","h"]
示例 2：
    输入：s = ["H","a","n","n","a","h"]
    输出：["h","a","n","n","a","H"]
*/

// 1-双指针
class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
        return;
    }
};
// 2-库函数reverse
class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};