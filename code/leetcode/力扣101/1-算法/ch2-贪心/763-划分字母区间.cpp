/*
字符串 S 由小写字母组成。
我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
返回一个表示每个字符串片段的长度的列表。

输入：S = "ababcbaca  defegde  hijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。

*/
#include<vector> 
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        // 很巧妙的方法
        // last数组代表26个英语字母分别在string s中最后一次出现的位置
        for (int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // end即为每个字母最后出现的位置
            end = max(end, last[s[i] - 'a']);
            // 判断当前位置是否是字母最后出现的位置
            // 是的话将区间长度加入结果
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
            
        }
        
        return res;
        
    }
};