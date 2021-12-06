/*
给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a*a + b*b = c 。

示例：
输入：c = 5
输出：true
解释：1 * 1 + 2 * 2 = 5

输入：c = 3
输出：false

输入：c = 4
输出：true

输入：c = 2
输出：true

输入：c = 1
输出：true
*/
#include<vector> 
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

// 一定要注意变量类型和结果范围啊
class Solution {
public:
    bool judgeSquareSum(int c) {
        long start = 0, end = (int)sqrt(c);
        
        while (start <= end)
        {
            long sum = start*start + end*end;
            if (sum == c)
            {
                return true;
            }
            else if (sum < c)
            {
                start++;
            }
            else if (sum > c)
            {
                end--;
            }   
        }
        return false;
    }
};