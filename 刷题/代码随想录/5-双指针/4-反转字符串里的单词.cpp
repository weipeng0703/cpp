/*
力扣剑指 Offer 151. 颠倒字符串中的单词
给你一个字符串 s ，颠倒字符串中 单词 的顺序。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

示例 1：
    输入：s = "the sky is blue"
    输出："blue is sky the"
示例 2：
    输入：s = "  hello world  "
    输出："world hello"
    解释：颠倒后的字符串中不能存在前导空格和尾随空格。
示例 3：
输入：s = "a good   example"
    输出："example good a"
    解释：如果两个单词间有多余的空格，颠倒后的字符串需要将单词间的空格减少到仅有一个。
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

// 步骤
// 1.去除原字符串中最前面与最后面的空格，去除字符串中单词间多余的空格使只留一个
// 2.整体将s翻转
// 3.遍历翻转后的字符串，对单独的单词在进行一次翻转
class Solution {
public:
    // 反转操作
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) swap(s[i], s[j]);
    }

    // 清除两个及以上空格中的多余空格，使只留下两个单词间的一个空格
    void removeExtraSpace(string& s) {
        int slow = 0, fast = 0;
        // 去除字符串最前面的空格
        while (s.size() > 0 && fast < s.size() && s[fast] == ' ') fast++;
        // 去除字符串中单词之间的多余空格，使两个单词间的空格只有一个
        for (; fast < s.size(); fast++)
        {
            if (fast - 1 > 0 && s[fast] == s[fast - 1] && s[fast] == ' ') {
                continue;
            } else {
                s[slow] = s[fast];
                slow++;
            }
        }
        // 去掉字符串最后面的空格
        if (slow - 1 > 0 && s[slow - 1] == ' ') {
            s.resize(slow - 1);
        } else {
            s.resize(slow);
        }
    }
    string reverseWords(string s) {
        removeExtraSpace(s);
        reverse(s, 0, s.size() - 1);

        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && s[j] != ' ') j++;
            // 将之前全部反转的单词反转回来
            reverse(s, i, j - 1);
            i = j;
        }
        return s;
    }
};