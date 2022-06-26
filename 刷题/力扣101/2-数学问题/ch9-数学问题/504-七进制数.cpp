/*
给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。


示例 1:

    输入: num = 100
    输出: "202"
示例 2:

    输入: num = -7
    输出: "-10"
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<priority_queue>
using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        // 细节1，如果为0，直接输出"0"
        if (num == 0)
        {
            return "0";
        }
        // 用于记录原数
        int temp = num;
        // 细节2，如果小于0，将其转换为正数再去做
        if (temp < 0)
        {
            num = -num;
        }
        
        string ans;
        while (num)
        {
            int a = num / 7, b = num % 7;
            ans = to_string(b) + ans;
            num = a;
        }
        // 细节三，最后输出时别忘了判断原数正负
        if (temp > 0)
        {
            return ans;
        }
        else
        {
            return "-" + ans;
        }
        
    }
};
