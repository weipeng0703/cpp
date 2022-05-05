/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-30 09:35:16
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-30 09:35:16
 */
/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-04-29 09:12:19
 * @LastEditors: weipeng
 * @LastEditTime: 2022-04-29 13:25:01
 */
/*
力扣455. 分发饼干
假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。
对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；
并且每块饼干 j，都有一个尺寸 s[j] 。
如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。
你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。 
示例 1:
    输入: g = [1,2,3], s = [1,1]
    输出: 1
    解释: 
    你有三个孩子和两块小饼干，3个孩子的胃口值分别是：1,2,3。
    虽然你有两块小饼干，由于他们的尺寸都是1，你只能让胃口值是1的孩子满足。
    所以你应该输出1。
示例 2:
    输入: g = [1,2], s = [1,2,3]
    输出: 2
    解释: 
    你有两个孩子和三块小饼干，2个孩子的胃口值分别是1,2。
    你拥有的饼干数量和尺寸都足以让所有孩子满足。
    所以你应该输出2.

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
#include<unordered_map>
#include<priority_queue>
using namespace std; 

// 1.优先大饼干喂饱大胃口
// 以学生的视角进行循环
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) return 0;
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && s[index] >= g[i]) {
                count++;
                index--;
            }
        }
        return count;
    }
};

// 2.优先小饼干喂饱小胃口
// 以饼干的视角进行循环
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        for (int i = 0; i < s.size(); i++) {
            if (index < g.size() && s[i] >= g[index]) index++;
        }
        return index;
    }
};