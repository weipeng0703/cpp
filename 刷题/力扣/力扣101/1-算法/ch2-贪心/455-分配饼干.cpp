/*
有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。
每个孩子只能吃一个饼干，且只有饼干的大小不小于孩子的饥饿度时，这个孩子才能吃饱。
求解最多有多少孩子可以吃饱。

输入输出样例
输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数量。
Input: [1,2], [1,2,3]
Output: 2
在这个样例中，我们可以给两个孩子喂 [1,2]、[1,3]、[2,3] 这三种组合的任意一种。
*/
#include<vector> 
#include<algorithm>
using namespace std;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // 分别对两个数组进行排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int child = 0, cookie = 0;
        while (child < g.size() && cookie < s.size())
        {
            // 将饥饿度最小的孩子跟最小分量的饼干比较
            // 可以的话，则该孩子满足要求
            if (g[child] <= s[cookie])
            {
                child++;
                
            }
            // 之后饼干依次增大，与下一个孩子的饥饿度比较大小
            cookie++;
        }
        return child;
        
    }
};