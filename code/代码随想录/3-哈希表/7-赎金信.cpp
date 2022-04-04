/*
力扣383. 赎金信
给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
如果可以，返回 true ；否则返回 false 。
magazine 中的每个字符只能在 ransomNote 中使用一次。
 
示例 1：
    输入：ransomNote = "a", magazine = "b"
    输出：false
示例 2：
    输入：ransomNote = "aa", magazine = "ab"
    输出：false
示例 3：
    输入：ransomNote = "aa", magazine = "aab"
    输出：true
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

// 1.(只有26个字母)用开销小的数组代替unordered_map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (magazine.size() == 0) return false;
        vector<int> temp(26, 0);

        for (auto ele : magazine) ++temp[ele - 'a'];
        for (auto ele : ransomNote)
        {
            if (temp[ele - 'a'] == 0) return false;
            if (temp[ele - 'a'] != 0) --temp[ele - 'a'];
        }
        return true;
    }
};