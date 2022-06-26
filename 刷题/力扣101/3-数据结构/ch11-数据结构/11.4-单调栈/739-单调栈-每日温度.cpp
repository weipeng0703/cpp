/*
请根据每日 气温 列表 temperatures ，请计算在每一天需要等几天才会有更高的温度。
如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:

    输入: temperatures = [73,74,75,71,69,72,76,73]
    输出: [1,1,4,2,1,1,0,0]
示例 2:

    输入: temperatures = [30,40,50,60]
    输出: [1,1,1,0]
示例 3:

    输入: temperatures = [30,60,90]
    输出: [1,1,0]

*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 方法一：暴力法遍历，但是会超时
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        if (size == 1)
        {
            return vector<int> {0};
        }
        // 注意点一：可以直接让结果数组大小等于原来数组大小，对应着天数相同
        vector<int> res(size, 0);
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (temperatures[j] - temperatures[i] > 0)
                {
                    // 注意点二：可以直接令结果数组中当天等于j-i，
                    // 这样如果没有比当天气温高的话该位置答案直接就是0，不用计算
                    res[i] = j - i;
                    break;
                }
            }
        }
        return res;
    }
};

// 方法二：单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        // 栈用来存储第几天
        stack<int> temp;
        // 遍历温度数组
        for (int i = 0; i < n; i++)
        {
            // while循环比较当前数和栈里之前所有比他小的数
            // temperatures[temp.top()]表示当前栈中第一个需要比较的天数
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()])
            {
                // 比较第t天与当前天
                auto t = temp.top();
                // 将第t天抛出，继续比较下一天
                temp.pop();
                // 第t天的结果就是当前的第i天减第t天
                res[t] = i - t;
            }
            // 最后将第i天放入栈中
            temp.push(i);
        }
        return res;
    }
};