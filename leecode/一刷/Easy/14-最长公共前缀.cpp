/*
14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。

示例 1：
    输入：strs = ["flower","flow","flight"]
    输出："fl"
示例 2：
    输入：strs = ["dog","racecar","car"]
    输出：""
    解释：输入不存在公共前缀。
*/
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;

// 1.纵向比较法——依次比较字符串对应位置的字符是否相同
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0)   // 字符串数组为空的情况
        {
            return "";
        }
        
        for (int i = 0; i < strs[0].size(); ++i)   // 正常字符串数组的情况
        {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
            {
                if (i == strs[j].size() || strs[j][i] != c)
                {
                    return strs[0].substr(0, i);
                }
                
            }
            
        }
        // 字符串数组只有一个字符串的情况
        return strs[0];
        
    }
};


// 2.横向比较法——依次比较字符串，更新最长公共前缀

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
        {
            return "";
        }
        
        string Optional = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            // 依次将其余字符串与第一个字符串比较
            Optional = CompareTwo(Optional, strs[i]);   
            if (Optional.size() == 0)
            {
                break;
            }
            
        }
        return Optional;
    }
    string CompareTwo(const string &str1, const string &str2)
    {
        int length = min(str1.size(), str2.size());
        int i = 0;
        while (i < length && str1[i] == str2[i])
        {
            ++i;
        }
        return str1.substr(0,i);
    }
};
