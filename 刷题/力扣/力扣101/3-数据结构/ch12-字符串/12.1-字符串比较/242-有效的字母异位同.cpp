/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

示例 1:
    输入: s = "anagram", t = "nagaram"
    输出: true
示例 2:
    输入: s = "rat", t = "car"
    输出: false
*/

#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.创建两个大小为26的数组，比较二者中字母对应的数位是否完全相等
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> counts_1(26, 0);
        vector<int> counts_2(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            counts_1[s[i] - 'a']++;
            counts_2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (counts_1[i] != counts_2[i])
            {
                return false;
            }
            
        }
        return true;
    }
};
// 2.只用一个大小为26的数组，第一个字符串做++操作，第二个做--操作，看最后是否是全零数组
// 是的话证明二者中字符相同
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> counts(26, 0);
        for (int i = 0; i < s.size(); i++)
        {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (counts[i] != 0)
            {
                return false;
            }
            
        }
        return true;
    }
};