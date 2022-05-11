/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-11 08:51:59
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-11 09:40:48
 */
/*
力扣474. 一和零
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。

示例 1：
    输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
    输出：4
    解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
    其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。
示例 2：
    输入：strs = ["10", "0", "1"], m = 1, n = 1
    输出：2
    解释：最大的子集是 {"0", "1"} ，所以答案是 2 。
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

// 问题转化：
// strs为待选物品的集合，其中每个物品只有一个
// m与n构成背包的两个维度，限定背包中物品的个数
// 所以该题转化为01背包问题，本质是有两个维度的01背包

// 1.dp-01背包问题
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        if (strs.size() == 0) return 0;
        // dp[i][j]表示最多有i个0和最多由j个1的最大子集的大小
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // 遍历strs数组中的元素
        for (string ele : strs) {
            int zeroNum = 0, oneNum = 0;
            // 统计某个字符中0和1的个数
            for (char c : ele) {
                if (c == '1') oneNum++;
                if (c == '0') zeroNum++;
            }
            // dp数组的遍历
            for (int i = m; i >= zeroNum; i--) {
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};