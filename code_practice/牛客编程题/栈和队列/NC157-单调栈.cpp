/*
描述
给定一个长度为 n 的可能含有重复值的数组 arr ，找到每一个 i 位置左边和右边离 i 位置最近且值比 arri 小的位置。

请设计算法，返回一个二维数组，表示所有位置相应的信息。
位置信息包括：两个数字 l 和 r，如果不存在，则值为 -1，下标从 0 开始。
 
进阶：空间复杂度 O(n) ，时间复杂度 O(n)

示例一：
    输入：[3,4,1,5,6,2,7]
    输出：[[-1,2],[0,2],[-1,-1],[2,5],[3,5],[2,-1],[5,-1]]

示例二：
    输入：[1,1,1,1]
    输出：[[-1,-1],[-1,-1],[-1,-1],[-1,-1]]
*/
#include<vector> 
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>
#include<priority_queue>
using namespace std;

// 方法一：暴力遍历,会超时
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums intvector 
     * @return intvector<vector<>>
     */
    vector<vector<int> > foundMonotoneStack(vector<int>& nums) {
        // write code here
        int n=nums.size();
        vector<vector<int>> array(n);//定义一个n行两列的二维数组存放结果
        for (int i = 0; i < array.size(); i++)
              array[i].resize(2);
        for(int i=0;i<n;i++)
        {
            array[i][0]=-1;
            array[i][1]=-1;
            // 从nums开头开始计数
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])//左侧离 i 位置最近且值比 arr[i] 小的位置
                    array[i][0]=j;
            }
            for(int j=n-1;j>i;j--)
            {
                if(nums[j]<nums[i])//右侧离 i 位置最近且值比 arr[i] 小的位置
                    array[i][1]=j;
            }
        }
        return array;
    }
};

// 方法二：从左到右和从右到左两次循环使用单调（递增）栈
// 如果搞不清楚比较大小的方向和递增递减栈可以简单用画个图看一下
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums intvector 
     * @return intvector<vector<>>
     */
    vector<vector<int> > foundMonotoneStack(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res(n);
        // 构建n行2列的结果数组
        for (int i = 0; i < res.size(); i++)
        {
            res[i].resize(2);
        }
        for (int i = 0; i < n; i++)
        {
            // 最开始将结果元素全部初始化为-1
            res[i][0] = -1;
            res[i][1] = -1;
        }
        // 构建单调栈
        stack<int> st;
        // 先从左往右遍历，确认res[i][1]
        for (int i = 0; i < n; i++)
        {
            // 注意比较时要严格小于大于
            while (!st.empty() && nums[i] < nums[st.top()])
            {
                auto t = st.top();
                st.pop();
                res[t][1] = i;
            }
            st.push(i);
        }
        // 清空栈
        while (!st.empty())
        {
            st.pop();
        }
        
        // 再从右往左遍历，确认res[i][0]
        for (int i = n - 1; i >= 0; i--)
        {
            // 注意比较时要严格小于大于
            while (!st.empty() && nums[i] < nums[st.top()])
            {
                auto t = st.top();
                st.pop();
                res[t][0] = i;
            }
            st.push(i);
        }
        
        return res;
    }
};