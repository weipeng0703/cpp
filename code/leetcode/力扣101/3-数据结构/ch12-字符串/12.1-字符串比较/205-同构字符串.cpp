/*
给定两个字符串 s 和 t，判断它们是否是同构的。
如果 s 中的字符可以按某种映射关系替换得到 t ，那么这两个字符串是同构的。
每个出现的字符都应当映射到另一个字符，同时不改变字符的顺序。
不同字符不能映射到同一个字符上，相同字符只能映射到同一个字符上，字符可以映射到自己本身。

示例 1:
    输入：s = "egg", t = "add"
    输出：true
示例 2：
    输入：s = "foo", t = "bar"
    输出：false
示例 3：
    输入：s = "paper", t = "title"
    输出：true
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 1.可以构建两个数组（当然最通俗的理解方法是哈希表，但是数组肯定是比哈希表快的），
// 分别用于记录两个字符串中每个位置的字符第一次出现的位置。
// 如果两个字符串中相同位置的字符与他们第一次出现时的位置一样，那满足条件
// 例如paper与title,遍历到第三个位置p和t,发现他们第一次出现时都在第一个字符，说明目前为止满足条件
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        vector<int> first_1(256, 0);    // ASCII码表的大小
        vector<int> first_2(256, 0);

        for (int i = 0; i < s.size(); i++)
        {
            if (first_1[s[i]] != first_2[t[i]])
            {
                return false;
            }
            // char强转为int,例如如果是'a'的话转为97;
            // i+1代表该字符在字符串中出现的位置，
            // 如果仅出现一次即为其出现的位置，如果多次出现即每次变为当前出现的位置
            first_1[s[i]] = i + 1;
            first_2[t[i]] = i + 1;
        }
        return true;
    }
};

// 2.巧妙方法——使用find()返回字符串中每个字母第一次出现的位置
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        for(int i = 0; i < s.size(); i++)
            if(s.find(s[i]) != t.find(t[i]))
                return false;
        return true;
    }
};
