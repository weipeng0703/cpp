/*
给定一个字符串 s，统计并返回具有相同数量 0 和 1 的非空（连续）子字符串的数量，
并且这些子字符串中的所有 0 和所有 1 都是成组连续的。
重复出现（不同位置）的子串也要统计它们出现的次数。
 
示例 1：
    输入：s = "00110011"
    输出：6
    解释：6 个子串满足具有相同数量的连续 1 和 0 ："0011"、"01"、"1100"、"10"、"0011" 和 "01" 。
    注意，一些重复出现的子串（不同位置）要统计它们出现的次数。
    另外，"00110011" 不是有效的子串，因为所有的 0（还有 1 ）没有组合在一起。
示例 2：
    输入：s = "10101"
    输出：4
    解释：有 4 个子串："10"、"01"、"10"、"01" ，具有相同数量的连续 1 和 0 。
*/

#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.统计相邻的相同字符的个数之后再进行最小值求和
// 时间与空间复杂度都为n
class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> counts;     // 用动态数组而不是普通数组，可以动态扩充且不需要提前考虑数组大小
        int ptr = 0, n = s.size();
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            counts.push_back(count);
        }
        
        int sum = 0;
        for (int i = 1; i < counts.size(); i++)
        {
            sum += min(counts[i - 1], counts[i]);
        }
        return sum;
    }
};

// 2.优化
// 对于某一个位置 i，其实我们只关心 i - 1 位置的 counts 值是多少，
// 所以可以用一个 last 变量来维护当前位置的前一个位置，
// 这样可以省去一个 counts 数组的空间。
// 时间复杂度为n，空间复杂度为1

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ptr = 0, n = s.size(), last = 0, sum = 0;
        while (ptr < n) {
            char c = s[ptr];
            int count = 0;
            while (ptr < n && s[ptr] == c) {
                ++ptr;
                ++count;
            }
            // last为当前字符前一个字符的count值，count为当前字符的
            sum += min(last, count);
            last = count;
        }
        return sum;
    }
};