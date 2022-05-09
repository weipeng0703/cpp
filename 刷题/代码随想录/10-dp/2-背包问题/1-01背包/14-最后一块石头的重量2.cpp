/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: weipeng
 * @Date: 2022-05-09 09:46:52
 * @LastEditors: weipeng
 * @LastEditTime: 2022-05-09 10:46:28
 */
/*
力扣1049. 最后一块石头的重量 II
有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。
每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
    如果 x == y，那么两块石头都会被完全粉碎；
    如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

示例 1：
    输入：stones = [2,7,4,1,8,1]
    输出：1
    解释：
    组合 2 和 4，得到 2，所以数组转化为 [2,7,1,8,1]，
    组合 7 和 8，得到 1，所以数组转化为 [2,1,1,1]，
    组合 2 和 1，得到 1，所以数组转化为 [1,1,1]，
    组合 1 和 1，得到 0，所以数组转化为 [1]，这就是最优值。
示例 2：
    输入：stones = [31,26,33,21,40]
    输出：5
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

// 问题转化：把一堆石头分成两堆,求两堆石头重量差最小值
// 进一步：要让差值小,两堆石头的重量都要接近sum/2;
//         我们假设两堆分别为 A,B ,A < sum / 2, B > sum / 2,若A更接近sum / 2,B也相应更接近sum / 2
// 进一步：将一堆stone放进最大容量为sum/2的背包,求放进去的石头的最大重量MaxWeight,最终剩下的即为sum-2*MaxWeight;
// 进一步：问题转化为13题

// 1. dp(01背包问题)
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if (stones.size() == 1) return stones[0];
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum / 2;
        vector<int> dp(target + 1, 0);
        for (int i = 0; i < stone.size(); i++) {
            for (int j = target; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
};


