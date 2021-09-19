/*
给你一个字符串 s，由若干单词组成，单词前后用一些空格字符隔开。
返回字符串中最后一个单词的长度。
单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

示例 1：
    输入：s = "Hello World"
    输出：5
示例 2：
    输入：s = "   fly me   to   the moon  "
    输出：4
示例 3：
    输入：s = "luffy is still joyboy"
    输出：6

*/
#include<string>
using namespace std;

// 1.自己写的暴力解法，测试没问题，但是会超出时间限制
// 注意：char(32) == " ";
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        if(n == 1)
        {
            return 1;
        }
        for (int i = n-1; i >= 0; i--)
        {   
            // cout << "正序" << endl;
            // cout << s[i] << " ";
            // cout << "逆序" << endl;
            // cout << s[i] << " ";
            // 1.考虑句子末尾没有空格
            if (s[n - 1] != char(32))
            {
                int flag = 0;
                if (s[i] == char(32))
                {
                    flag = i;
                    // cout << s.substr(i+1,(n-1-i+1)) << endl;
                    // cout << s.substr(i+1,(n-1-i+1)).size() << endl;
                    return s.substr(i+1,(n-1-i+1)).size();
                    // break;
                }
                
            }

            else if(s[n - 1] == char(32))
            {
                while (s[i] != char(32))
                {
                    for (int j = i; i > 0; j--)
                    {
                        if (s[j] == char(32))
                        {
                            // cout << s.substr(j+1, i - j) << endl;
                            // cout << s.substr(j+1, i - j).size() << endl;
                            return s.substr(j+1, i - j).size();
                        }

                        
                    }
                                
                }

            }
        // }
    }
    return 0;
    }
};

// 2.仍然是暴力，但是简单很多
class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        if (s.size() == 1)
        {
            return 1;
        }
        for (int i = s.size() - 1; i >= 0; i--) 
        {
            if (s[i] != ' ') 
            {
                length++;
            } 
            else if (length != 0) 
            {
                return length;
            }
        }
        return length;
    }
};