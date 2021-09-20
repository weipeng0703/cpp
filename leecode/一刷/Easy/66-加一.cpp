/*
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。


示例 1：
    输入：digits = [1,2,3]
    输出：[1,2,4]
    解释：输入数组表示数字 123。
示例 2：
    输入：digits = [4,3,2,1]
    输出：[4,3,2,2]
    解释：输入数组表示数字 4321。
示例 3：
    输入：digits = [0]
    输出：[1]

提示：
    1 <= digits.length <= 100
    0 <= digits[i] <= 9
*/
#include<vector>
using namespace std;

// 1.自己的解法，没有考虑数据的大小范围问题，如果遇到9会溢出
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> v;
        for (int i = 0; i < digits.size(); i++)
        {
            v.push_back(digits[i]);
        }

        if (v[digits.size()-1] == 9)
        {
            v[digits.size()-1] = 0;
            v[digits.size()-2] = 1;
        }
        else
        {
            v.back()++;
        }
        return v; 
    }
};

// 2、
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        digits[size - 1] += 1;
        for(int i = size - 1;i > 0;i--)
        {
            if(digits[i] == 10)
            {
                digits[i-1] = digits[i-1]+1;
                digits[i] = 0;
            }
        }

        if(digits[0] == 10)
        {
            digits[0] = 1;
            for(int i = 1; i < size; i++)
            {
                digits[i] = 0;
            }
            digits.push_back(0);
        }
        return digits;
    }
};

// 3.
// 也有错误，内存溢出
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum = 0;
        int size = digits.size();
        for (int i = size; i >= 0; i--)
        {
            sum += digits[size - i] * 10 * (size - i - 1);
        }

        vector<int> v;
        while (sum != 0)
        {
            int flag = sum % 10;
            v.push_back(flag);
        }
        
        vector<int> v1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            v1.push_back(v[i]);
        }

        return v1;
        
        
        
    }
};