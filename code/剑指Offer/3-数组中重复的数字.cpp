/*
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 
数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。
请找出数组中 任意一个 重复的数字。 
例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。
存在不合法的输入的话输出-1
    
示例一：
输入：
[2,3,1,0,2,5,3]
返回值：
2
说明：
2或3都是对的   
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
using namespace std; 

// 1.排序遍历：将数组排序后从头到尾遍历数组即可
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        int n = numbers.size();
        if (n == 0)
        {
            return -1;
        }
        int ans;
        sort(numbers.begin(), numbers.end());
        for (int i = 1; i < n; i++)
        {
            if (numbers[i] == numbers[i - 1])
            {
                ans = numbers[i];
                break;
            }
        }
        return ans;
    }
};
// 时间复杂度：排序长度为n的数组O(nlogn)

// 2.重排数组法
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        int n = numbers.size();
        if (n == 0)
        {
            return -1;
        }
        int ans;
        for (int i = 0; i < n; i++)
        {
            while (numbers[i] != i)
            {
                if (numbers[i] == numbers[numbers[i]])
                {
                    ans = numbers[i];
                    break;
                }
                int temp = numbers[i];
                numbers[i] = numbers[temp];
                numbers[temp] = temp;
            }
            
        }
        return ans;
        
    }
};
// 代码使用了循环，循环次数为数组大小，因此该方法的时间复杂度为O(N)。
// 时间复杂度O(N)
// 由于没有采用额外的数组空间，空间复杂度为O(1)

// 3.set集合
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int duplicate(vector<int>& numbers) {
        // write code here
        set<int> s;
        for(int i=0;i<numbers.size();i++){
            if(s.count(numbers[i])>0)
                return numbers[i];
            else
                s.insert(numbers[i]);
        }
        return -1;
    }
};
// 代码使用了循环，循环次数为数组大小，因此该方法的时间复杂度为O(N)。
// 由于引入额外的集合空间，因此空间复杂度为O(N)，最坏的情况是数组中的元素都不重复。